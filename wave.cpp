
#include <iostream>
#include <fstream>

using namespace std;
float getfrequency(char hh_);
float getAmplitude(int ss_);
float getLength(int eumpyo);
float* fRead(void);

int main() {
	ifstream xx("Beatles.wav", ios::binary | ios::in);
	if (!xx) return 999;  // if the file is not found
	char header[44];
	

	// Sprint 1
	xx.read(header, 44);
	xx.close();
	int* sampleRate = (int*)(header + 24);
	cout << "   sampleRate = " << *sampleRate << endl;
	short* n;   n = (short*)(header + 22);  cout << *n << endl; // numChannels
	int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; // sampleRate
	int* b;   b = (int*)(header + 28);  cout << *b << endl;  //  byteRate
	*n = 1;  // mono

	// Sprint 3
	int N = fs[0]; // number of samples for 1 second
	short* data;
	data = new short[N]; // allocate memory for 1 seconds mono
	const float pi = 3.141592;

	ofstream yy("my3.wav", ios::binary | ios::out);
	if (!yy) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
	yy.write(header, 44 * sizeof(char)); // ����� ����.


	//txt ������ �а�, �� ������ wav������ �����
	float dt = 1. / fs[0];
	float* read_file = fRead();
	for (int i = 0; i < read_file[0]; i++) {
		float T = read_file[5 * i + 1];
		float f_1 = read_file[5 * i + 2];
		float f_2 = read_file[5 * i + 3];
		float f_3 = read_file[5 * i + 4];
		float a = read_file[5 * i + 5];
		float t = 0.0;

		for (int j = 0; j < fs[0]; j++, t += dt) {
			data[j] = (short)(a * sin(2.0 * pi * f_1 * t) + a * sin(2.0 * pi * f_2 * t) + a * sin(2.0 * pi * f_3 * t));   // a ����, f ���ļ�, N ���ü�(1�ʴ� fs[0] samples, 44100 �Ǵ� 8000)
		}
		yy.write((char*)data, fs[0] * sizeof(short) * T);    // T�� �з� ����.
	}
	yy.close();
	return 1;
}

float getfrequency(char hh_) {
	float f;

	if (hh_ == 67) f = 261; // C (��)
	else if (hh_ == 68) f = 294; // D (��)
	else if (hh_ == 69) f = 330; // E	(��)
	else if (hh_ == 70) f = 349; // F	(��)
	else if (hh_ == 71) f = 392; // G	(��)
	else if (hh_ == 72) f = 440; // A	(��)
	else if (hh_ == 73) f = 494; // B	(��)
	else  f = 0; // ����

	return f;
}

float getAmplitude(int ss_) {
	float a;
	a = ss_ * 1000.0;
	return a;
}

float getLength(int eumpyo) {
	float T = 0.0;
	if (eumpyo == 4) T = 1.0;
	else if (eumpyo == 6) T = 0.75; // ��8����ǥ 0.75��
	else if (eumpyo == 8) T = 0.5; // 8����ǥ�� 0.5��
	else if (eumpyo == 16) T = 0.25; // 16����ǥ�� 0.25��
	else T = 2.0; // 2����ǥ�� 2��
	return T;
}


float* fRead(void) {
	ifstream zz("myWave.txt");
	float f_1, f_2, f_3, a, T;
	char hh_1, hh_2, hh_3;
	int n, eu, ss;
	float* result;

	zz >> n; // ��ǥ�� �� ������ �б�

	result = new float[n * 5 + 1]; // (4byte * n *5) + 1 ��ŭ �޸� Ȯ��

	result[0] = n;

	for (int i = 0; i < n; i++) {
		zz >> eu >> hh_1 >> hh_2 >> hh_3 >> ss;  // eu ss�� int�̰�, hh�� char
		f_1 = getfrequency(hh_1);
		f_2 = getfrequency(hh_2);
		f_3 = getfrequency(hh_3);    // ���ļ��� return �Ǵ� �Լ�
		a = getAmplitude(ss);    // ������ return�Ǵ� �Լ�
		T = getLength(eu);       // �ð��� return�Ǵ� �Լ�

		result[5 * i + 1] = T;
		result[5 * i + 2] = f_1;
		result[5 * i + 3] = f_2;��
		result[5 * i + 4] = f_3;
		result[5 * i + 5] = a;

	}

	return result;
}
// ���� wave file �ݱ�

