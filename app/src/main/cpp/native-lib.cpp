#include <jni.h>
#include <string>
#include <vector>
#include "log.h"
using namespace std;
#define PI 3.14 // 常量
string printVector(vector<int> &vec);
void printArray(int (*arr)[3], int row);

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_basecdemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    const int a = 30; // 常量
    LOGD("常量 PI = %f, a = %d", PI, a);
    int b = -1; // 1000 0001 转unsigned int b = 129 (2^7 + 1)
    unsigned int c = 5;
    LOGD("整形 b = %d, c = %u, 大小=%d", b, c, b > c);
    bool isCopy = true;
    LOGI("布尔 isCopy = %d", isCopy);

    char chs[] = "yyyyddmmdd";
    LOGI("字符串 chs = %s", chs);
    char cc = 'A';
    LOGI("字符 cc = %c", cc);

    float ff = 3.14;
    double dd = 3.1415;
    LOGI("单精度 ff = %f, 双精度 dd = %lf", ff, dd);


    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_basecdemo_MainActivity_testString(JNIEnv *env, jobject thiz) {
    string s = "我用c++，我很快乐";
    string s1 = s;
    //string s2 = 'a';
    string s3;
    s3.assign("我用c++，我很快乐");
    string s4;
    s4.assign("我用c++，我很快乐", 5);
    string s5;
    s5.assign(s4);
    string s6;
    s6.assign(s5, 1, 3);
    LOGD("s = %s, s2 = %s, s4 = %s, s6 = %s", s.c_str(), "s2 string", s4.c_str(), s6.c_str());

    // 字符串拼接
    //第一种用法
    string str1 = "我";
    str1 += "在学c++";
    str1 += '!';
    string str2 = "发现学习如此轻松，没有想象中那么难";
    str1 += str2;
    //第二种用法
    string str3 = "12345";
    char *cc = "678910";
    string str4 = "678";
    str3.append(str4);
    str3.append(cc);
    str3.append(cc, 2); // 前两个字符，也就是 67
    str3.append(str4, 2, 3); // 从第二个开始到结束的3个字符
    LOGD("str1 = %s, str3 = %s", str1.c_str(), str3.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_basecdemo_MainActivity_testVector(JNIEnv *env, jobject thiz) {
    vector<int> vec;
    vector<int> vec1(3);
    vector<int> vec2(3, 2);
    vector<int> vec3(vec2);
    int size = vec3.size();
    string result;
    for (int i = 0; i < size; i++) {
        result += to_string(vec3[i]);
        result += " ";
    }
    LOGD("result = %s", result.c_str());

    vec3.push_back(1);
    vec3.insert(vec3.begin() + 1, 0);
    vec3.insert(vec3.begin() + 2, 2, 5);
    vector<int> vec4 {11, 22, 33, 44, 55};
    vec3.insert(vec3.begin() + 3, vec4.begin() + 1, vec4.end());
    string vec3Result = printVector(vec3);
    LOGD("vec3Result = %s", vec3Result.c_str());

    vec3.erase(vec3.begin());
    vec3.pop_back();
    LOGD("delete vec3Result = %s", printVector(vec3).c_str());
}

string printVector(vector<int> &vec) {
    int size = vec.size();
    string result;
    for (int i = 0; i < size; i++) {
        result += to_string(vec[i]);
        result += " ";
    }
    return result;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_basecdemo_MainActivity_testArray(JNIEnv *env, jobject thiz) {
    int arr1[4] = {1,2,3,4};
    int arr2[4] = { 1,2 };
    int arr[4] = {0};  //  所有元素为0
    static int arr3[3];
    int arr4[4];
    LOGD("arr1:%d, %d, %d, %d", arr1[0], arr1[1], arr1[2], arr1[3]);
    LOGD("arr2:%d, %d, %d, %d", arr2[0], arr2[1], arr2[2], arr2[3]);
    LOGD("arr:%d, %d, %d, %d", arr[0], arr[1], arr[2], arr[3]);
    LOGD("arr3:%d, %d, %d, %d", arr3[0], arr3[1], arr3[2], arr3[3]);
    LOGD("arr4:%d, %d, %d, %d", arr4[0], arr4[1], arr4[2], arr4[3]);

    int arr5[2][3];
    int arr6[2][3] = {0};//所有元素为0
    int arr7[2][3] = { {1,2,3},{4,5,6} };
    int arr8[2][3] = { 1,2,3 ,4,5,6 };
    int arr9[2][3] = {{1}, {4,6}};
    int arr10[][3] = { 1,2,3 ,4,5,6 };
    int (*p)[3] = arr5;
    printArray(p, 2);
    printArray(arr6, 2);
    printArray(arr7, 2);
    printArray(arr8, 2);
    printArray(arr9, 2);
    printArray(arr10, 2);

    int arr11[2] = {8, 9};
    int *a = arr11; // a = arr11 or a = &arr11[0]
    LOGD("arr11:%d, %d", *a, *(a + 1));

    int* arr12 = new int[2];  //  delete []arr12;
    int* arr13 = new int[3]{ 1,2 };  //  delete []arr13
    int m=2, n=3;
    int** arr31 = new int*[2];//delete []arr3
    for (int i = 0; i < 10; ++i)
    {
        arr31[i] = new int[3];   // delete []arr3[i]
    }
    int* arr32 = new int[m*n];  //  数据按行存储 delete []arr3
}

void printArray(int (*arr)[3], int row) {
    string result;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < 3; ++j) {
            result += to_string(arr[i][j]);
            result += " ";
        }
    }
    LOGD("arr[%s]", result.c_str());
}