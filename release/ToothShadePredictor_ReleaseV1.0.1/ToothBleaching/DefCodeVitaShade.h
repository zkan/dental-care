#pragma once

#include <string>
#include <sstream>

using namespace System::Collections;
using namespace std ;

#define NUM_CODE	16
#define B1			1
#define A1			2
#define B2			3
#define D2			4
#define A2			5
#define C1			6
#define C2			7
#define D4			8
#define A3			9
#define D3			10
#define B3			11
#define A3_5		12
#define B4			13
#define C3			14
#define A4			15
#define C4			16


#define SB1			"B1"
#define SA1			"A1"
#define SB2			"B2"
#define SD2			"D2"
#define SA2			"A2"
#define SC1			"C1"
#define SC2			"C2"
#define SD4			"D4"
#define SA3			"A3"
#define SD3			"D3"
#define SB3			"B3"
#define SA3_5		"A3.5"
#define SB4			"B4"
#define SC3			"C3"
#define SA4			"A4"
#define SC4			"C4"

#define IMG_FOLDER	"vita_img/"

typedef struct
{
	int code[NUM_CODE] ;

}VITA_CODE;

const int _Vita_Code_[NUM_CODE] = {B1,A1,B2,D2,A2,C1,C2,D4,A3,D3,B3,A3_5,B4,C3,A4,C4} ;
const string _SVita_Code[NUM_CODE] = {SB1,SA1,SB2,SD2,SA2,SC1,SC2,SD4,SA3,SD3,SB3,SA3_5,SB4,SC3,SA4,SC4};

#include <iostream>
#include <string.h>

template <typename T>
class SimpleHash {
private:
    // data
    T* m_pData;
    // hash table size
    unsigned int m_size;

    // djb2 hash function
    unsigned int djb2(const char* key) {
        unsigned int hash = 5381;

        for (unsigned int i = 0; i < strlen(key); i++)
            hash = ((hash << 5) + hash) + (unsigned int)key[i];

        return hash % m_size;
    }

public:
    SimpleHash(unsigned int size): m_size(size) {
        // init hash table data given table size
        m_pData = new T[m_size];
    }

    ~SimpleHash() {
        delete[] m_pData;
    }

    void set(const char* key, const T& value) {
        unsigned int index = djb2(key);
        std::cout << "set " << index << ": " << value  << std::endl;
        m_pData[index] = value;
    }

    T get(const char* key) {
        unsigned int index = djb2(key);
        std::cout << "get " << index << std::endl;
        return m_pData[index];
    }
};

class DefCodeVitaShade
{
public:
	//Hashtable ^hash ;
	
	DefCodeVitaShade(void);
	void InitialData(void);
	string  convertInt(int number);
	int getVitaCodeIndex(string vitacode);

};
