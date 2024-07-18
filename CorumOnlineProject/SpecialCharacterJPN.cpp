#include "CharSelectProcess.h"
#include "Define.h"
//---------------------------------------------------------------
//
//		Written By DeepDark, Special Character Check Functions..
//
//---------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct __Range4Double
{
	unsigned short usStart;
	unsigned short usEnd;

	BOOL IsInRange(unsigned short usChar) 
	{ return (usChar >= usStart && usChar <= usEnd); }

} DOUBLE_RANGE;

typedef struct __Range4Single
{
	BYTE ucStart;
	BYTE ucEnd;

	BOOL IsInRange(unsigned char ucChar)	
	{ return (ucChar >= ucStart && ucChar <= ucEnd); }

} SINGLE_RANGE;

// �Ϻ��� ���� ��� ����....
DOUBLE_RANGE RangeArrayDoubleByte[] =
{
#if IS_JAPAN_LOCALIZING()
	// 2 BYTE Characters.
	{ 0x815b, 0x815b }, // Katakana-Hiragana Prolonged Sound Mark
	{ 0x8199, 0x81a5 }, // White Star ~ Black Down-pointing Ttriangle
	{ 0x81f2, 0x81f5 }, // Music Sharp Sign ~ Dagger
	{ 0x824F, 0x8258 }, // Fullwidth Digit Zero ~ Fullwidth Digit Nine
	{ 0x8260, 0x8279 }, // Fullwidth Latin Capital Letter A ~ Fullwidth Latin Capital Letter Z
	{ 0x8281, 0x829a }, // Fullwidth Latin Small Letter A ~ Fullwidth Latin Small Letter Z
	{ 0x829f, 0x82f1 }, // Hiragana Letter Small A ~ Hiragana Letter N
	{ 0x8340, 0x837e },	// Katakana Letter Small A ~ Katakana Letter Small Me 
	{ 0x8380, 0x8396 }, // Katakana Letter Small Mu ~ Katakana Letter Small Ke
	{ 0x8794, 0x8794 }, // N-Ary Summation
	{ 0x8740, 0x875d }, // Circled Digit One ~ Roman Numeral Ten
	{ 0xfa40, 0xfa49 }, // Small Roman Numeral One ~ Small Roman Numeral Ten

	// Kanji.. !!!!! TT
	{ 0x889f, 0x88fc },	{ 0x8940, 0x897e },	{ 0x8980, 0x89fc },	{ 0x8a40, 0x8a7e },	{ 0x8a80, 0x8afc },	{ 0x8b40, 0x8b7e },	
	{ 0x8b80, 0x8bfc },	{ 0x8c40, 0x8c7e },	{ 0x8c80, 0x8cfc },	{ 0x8d40, 0x8d7e },	{ 0x8d80, 0x8dfc },	{ 0x8e40, 0x8e7e },
	{ 0x8e80, 0x8efc },	{ 0x8f40, 0x8f7e },	{ 0x8f80, 0x8ffc },	{ 0x9040, 0x907e },	{ 0x9080, 0x90fc },	{ 0x9140, 0x917e },
	{ 0x9180, 0x91fc },	{ 0x9240, 0x927e },	{ 0x9280, 0x92fc },	{ 0x9340, 0x937e },	{ 0x9380, 0x93fc },	{ 0x9440, 0x947e },
	{ 0x9480, 0x94fc },	{ 0x9540, 0x957e },	{ 0x9580, 0x95fc },	{ 0x9640, 0x967e },	{ 0x9680, 0x96fc },	{ 0x9740, 0x977e }, 
	{ 0x9780, 0x97fc },	{ 0x9840, 0x9872 },	{ 0x989f, 0x98fc },	{ 0x9940, 0x997e },	{ 0x9980, 0x99fc },	{ 0x9a40, 0x9a7e },
	{ 0x9a80, 0x9afc },	{ 0x9b40, 0x9b7e },	{ 0x9b80, 0x9bfc },	{ 0x9c40, 0x9c7e },	{ 0x9c80, 0x9cfc },	{ 0x9d40, 0x9d7e },	
	{ 0x9d80, 0x9dfc },	{ 0x9e40, 0x9e7e },	{ 0x9e80, 0x9efc },	{ 0x9f40, 0x9f7e },	{ 0x9f80, 0x9ffc },	{ 0xe040, 0xe07e },
	{ 0xe080, 0xe0fc },	{ 0xe140, 0xe17e },	{ 0xe180, 0xe1fc },	{ 0xe240, 0xe27e },	{ 0xe280, 0xe2fc },	{ 0xe340, 0xe37e },
	{ 0xe380, 0xe3fc },	{ 0xe440, 0xe47e },	{ 0xe480, 0xe4fc },	{ 0xe540, 0xe57e },	{ 0xe580, 0xe5fc },	{ 0xe640, 0xe67e },
	{ 0xe680, 0xe6fc },	{ 0xe740, 0xe77e },	{ 0xe780, 0xe7fc },	{ 0xe840, 0xe87e },	{ 0xe880, 0xe8fc },	{ 0xe940, 0xe97e },	
	{ 0xe980, 0xe9fc },	{ 0xea40, 0xea7e },	{ 0xea80, 0xeaa4 },	{ 0xed40, 0xed7e },	{ 0xed80, 0xedfc },	{ 0xee40, 0xee7e },
	{ 0xee80, 0xeeec },	{ 0xfa5c, 0xfa7e },	{ 0xfa80, 0xfafc },	{ 0xfb40, 0xfb7e },	{ 0xfb80, 0xfbfc },	{ 0xfc40, 0xfc4b }
	
#else if IS_TAIWAN_LOCALIZING()
    { 0xa440, 0xa47e }, { 0xa4a1, 0xa57e }, { 0xa5a1, 0xa5fe }, { 0xa640, 0xa67e }, { 0xa6a1, 0xa6fe },
    { 0xa740, 0xa77e }, { 0xa7a1, 0xa7fe }, { 0xa840, 0xa87e }, { 0xa8a1, 0xa8fe }, { 0xa940, 0xa97e },
    { 0xa9a1, 0xa9fe }, { 0xaa40, 0xaa7e }, { 0xaaa1, 0xaafe }, { 0xab40, 0xab7e }, { 0xaba1, 0xabfe },
    { 0xac40, 0xac7e }, { 0xaca1, 0xacfe }, { 0xad40, 0xad7e }, { 0xada1, 0xadfe }, { 0xae40, 0xae7e },
    { 0xaea1, 0xaefe }, { 0xaf40, 0xaf7e }, { 0xafa1, 0xaffe }, { 0xb040, 0xb07e }, { 0xb0a1, 0xb0fe },
    { 0xb140, 0xb17e }, { 0xb1a1, 0xb1fe }, { 0xb240, 0xb27e }, { 0xb2a1, 0xb2fe }, { 0xb340, 0xb37e },
    { 0xb3a1, 0xb3fe }, { 0xb440, 0xb47e }, { 0xb4a1, 0xb4fe }, { 0xb540, 0xb57e }, { 0xb5a1, 0xb5fe },
    { 0xb640, 0xb67e }, { 0xb6a1, 0xb6fe }, { 0xb740, 0xb77e }, { 0xb7a1, 0xb7fe }, { 0xb840, 0xb87e },
    { 0xb8a1, 0xb8fe }, { 0xb940, 0xb97e }, { 0xb9a1, 0xb9fe }, { 0xba40, 0xba7e }, { 0xbaa1, 0xbafe },
    { 0xbb40, 0xbb7e }, { 0xbba1, 0xbbfe }, { 0xbc40, 0xbc7e }, { 0xbca1, 0xbcfe }, { 0xbd40, 0xbd7e },
    { 0xbda1, 0xbdfe }, { 0xbe40, 0xbe7e }, { 0xbea1, 0xbefe }, { 0xbf40, 0xbf7e }, { 0xbfa1, 0xbffe },
    { 0xc040, 0xc07e }, { 0xc0a1, 0xc0fe }, { 0xc140, 0xc17e }, { 0xc1a1, 0xc1fe }, { 0xc240, 0xc27e },
    { 0xc2a1, 0xc2fe }, { 0xc340, 0xc37e }, { 0xc3a1, 0xc3fe }, { 0xc440, 0xc47e }, { 0xc4a1, 0xc4fe },
    { 0xc540, 0xc57e }, { 0xc5a1, 0xc5fe }, { 0xc640, 0xc67e }, { 0xc940, 0xc97e }, { 0xc9a1, 0xc9fe },
    { 0xca40, 0xca7e }, { 0xcaa1, 0xcafe }, { 0xcb40, 0xcb7e }, { 0xcba1, 0xcbfe }, { 0xcc40, 0xcc7e },
    { 0xcca1, 0xccfe }, { 0xcd40, 0xcd7e }, { 0xcda1, 0xcdfe }, { 0xce40, 0xce7e }, { 0xcea1, 0xcefe },
    { 0xcf40, 0xcf7e }, { 0xcfa1, 0xcffe }, { 0xd040, 0xd07e }, { 0xd0a1, 0xd0fe }, { 0xd140, 0xd17e },
    { 0xd1a1, 0xd1fe }, { 0xd240, 0xd27e }, { 0xd2a1, 0xd2fe }, { 0xd340, 0xd37e }, { 0xd3a1, 0xd3fe },
    { 0xd440, 0xd47e }, { 0xd4a1, 0xd4fe }, { 0xd540, 0xd57e }, { 0xd5a1, 0xd5fe }, { 0xd640, 0xd67e },
    { 0xd6a1, 0xd6fe }, { 0xd740, 0xd77e }, { 0xd7a1, 0xd7fe }, { 0xd840, 0xd87e }, { 0xd8a1, 0xd8fe },
    { 0xd940, 0xd97e }, { 0xd9a1, 0xd9fe }, { 0xda40, 0xda7e }, { 0xdaa1, 0xdafe }, { 0xdb40, 0xdb7e },
    { 0xdba1, 0xdbfe }, { 0xdc40, 0xdc7e }, { 0xdca1, 0xdcfe }, { 0xdd40, 0xdd7e }, { 0xdda1, 0xddfe },
    { 0xde40, 0xde7e }, { 0xdea1, 0xdefe }, { 0xdf40, 0xdf7e }, { 0xdfa1, 0xdffe }, { 0xe040, 0xe07e },
    { 0xe0a1, 0xe0fe }, { 0xe140, 0xe17e }, { 0xe1a1, 0xe1fe }, { 0xe240, 0xe27e }, { 0xe2a1, 0xe2fe },
    { 0xe340, 0xe37e }, { 0xe3a1, 0xe3fe }, { 0xe440, 0xe47e }, { 0xe4a1, 0xe4fe }, { 0xe540, 0xe57e },
    { 0xe5a1, 0xe5fe }, { 0xe640, 0xe67e }, { 0xe6a1, 0xe6fe }, { 0xe740, 0xe77e }, { 0xe7a1, 0xe7fe },
    { 0xe840, 0xe87e }, { 0xe8a1, 0xe8fe }, { 0xe940, 0xe97e }, { 0xe9a1, 0xe9fe }, { 0xea40, 0xea7e },
    { 0xeaa1, 0xeafe }, { 0xeb40, 0xeb7e }, { 0xeba1, 0xebfe }, { 0xec40, 0xec7e }, { 0xeca1, 0xecfe },
    { 0xed40, 0xed7e }, { 0xeda1, 0xedfe }, { 0xee40, 0xee7e }, { 0xeea1, 0xeefe }, { 0xef40, 0xef7e },
    { 0xefa1, 0xeffe }, { 0xf040, 0xf07e }, { 0xf0a1, 0xf0fe }, { 0xf140, 0xf17e }, { 0xf1a1, 0xf1fe },
    { 0xf240, 0xf27e }, { 0xf2a1, 0xf2fe }, { 0xf340, 0xf37e }, { 0xf3a1, 0xf3fe }, { 0xf440, 0xf47e },
    { 0xf4a1, 0xf4fe }, { 0xf540, 0xf57e }, { 0xf5a1, 0xf5fe }, { 0xf640, 0xf67e }, { 0xf6a1, 0xf6fe },
    { 0xf740, 0xf77e }, { 0xf7a1, 0xf7fe }, { 0xf840, 0xf87e }, { 0xf8a1, 0xf8fe }, { 0xf940, 0xf97e },
    { 0xf9a1, 0xf9dc }  

#endif
	
};

SINGLE_RANGE RangeArraySingleByte[] =
{
#if IS_JAPAN_LOCALIZING()
	// 1 BYTE Characters.
	{ 0x30, 0x39 }, // Digit Zero ~ Digit Nine
	{ 0x41, 0x5a }, // Latin Capital Letter A ~ Latin Capital Letter Z
	{ 0x61, 0x7a }, // Small Letter A ~ Latin Small Letter Z
	{ 0xa6, 0xdf }  // Halfwidth Katakana Letter Wo ~ Halfwidth Katakana Semi-Voiced Sound Mark

#else if IS_TAIWAN_LOCALIZING()
	{ 0x30, 0x39 }, // Digit Zero ~ Digit Nine
	{ 0x41, 0x5a }, // Latin Capital Letter A ~ Latin Capital Letter Z
	{ 0x61, 0x7a } // Small Letter A ~ Latin Small Letter Z

#endif
};

#define ARRAY_COUNT(array) sizeof(array)/sizeof(array[0])

static BOOL __IsSpecialCharacter(unsigned short usChar)
{
	for(int i = 0; i < ARRAY_COUNT(RangeArrayDoubleByte); i++)
	{
		if(RangeArrayDoubleByte[i].IsInRange(usChar)) return FALSE;
	}

	return TRUE;
}

static BOOL __IsSpecialCharacter(unsigned char ucChar)
{
	for(int i = 0; i < ARRAY_COUNT(RangeArraySingleByte); i++)
	{
		if(RangeArraySingleByte[i].IsInRange(ucChar)) return FALSE;
	}

	return TRUE;
}

static BOOL __IsSpecialCharacter(char* szStr)
{
	int nLen = lstrlen(szStr);
	int i = 0;

	char* szTemp = szStr;

	for(;;)
	{
		char* szNext = CharNextExA(0, szTemp, 0);
		int iSize = szNext - szTemp;

		if(iSize == 1)
		{
			if(__IsSpecialCharacter(*(unsigned char*)szTemp))
				return TRUE;
		}
		else
		{
			if(__IsSpecialCharacter(MAKEWORD(*(unsigned char*)(szTemp+1), *(unsigned char*)szTemp)))
				return TRUE;
		}
		
		szTemp += iSize;
		i += iSize;

		if(i >= nLen) break;
	}

	return FALSE; //bSpecialCharacter;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
static BOOL IsSpecialCharacterKor(char* szCharacterName)
{	
	int nLen = lstrlen(szCharacterName);
	BOOL bSpecialCharacter = FALSE;

	BYTE szStr[ MAX_CHARACTER_NAME_LENGTH ];	
	memset(szStr, 0, MAX_CHARACTER_NAME_LENGTH);
	memcpy(szStr, szCharacterName, nLen);
	
	for(int i=0; i<nLen; i++)
	{
		if( ( szStr[i]>= 0xB0 ) && (szStr[i] <= 0xC8 ) && 
		( szStr[i+1] >= 0xA1 ) && ( szStr[i+1] <= 0xFE ) ) 
		{ /* �ѱ� �ش� �κ� */ 
			i++; 
		} 
		else if( ( szStr[i]>= 0xCA ) && (szStr[i] <= 0xFD ) 
		&& ( szStr[i+1] >= 0xA1 ) && ( szStr[i+1] <= 0xFE) ) 
		{ /* ���� �ش� �κ� */ 
			i++; 
			bSpecialCharacter = TRUE;
		} 
		else if ( ( ( szStr[i]>= 0x41 ) && 
		( szStr[i] <= 0x5A ) ) || 
		( ( szStr[i] >= 0x61 ) && ( szStr[i] <= 0x7A) ) ) 
		{ /* ���� �ش� �κ� */ 

		} 
		else if ( ( szStr[i]>= '0' ) && 
		( szStr[i] <= '9' ) ) /* ���� ó�� �κ� */ 
		{ 
		} 
		else if(( szStr[i]>= 0xA1 ) && ( szStr[i+1] >= 0xA1 ) ) 
		{ 
			/* 2byte special char */ 
			i++; 
			bSpecialCharacter = TRUE;
		} 
		else 
		{ 
			//1byte special character  
			bSpecialCharacter = TRUE;
		} 
	}
	
	return bSpecialCharacter;
}

static BOOL IsSpecialCharacterChn(char *pstr)
{
	if(pstr == NULL) return FALSE;

	char szFilter[] = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~�� "; // "<>\\/\"? '`"
	
	size_t size = _mbscspn((const unsigned char *)pstr, (const unsigned char *)szFilter);
	int length = lstrlen(pstr);

	if (size < (unsigned int)length)
		return TRUE;

	BYTE c1, c2;	
	while(*pstr != 0)
	{
		c1 = *pstr;

		if (c1<128)
		{
			pstr++;
			continue;
		}

		if (c1 & 0x80)
		{
			c2 = *(pstr+1);
			WORD flag = 0;
			flag = WORD(c1<<8|c2);
			if (flag>0xf7fe||flag<0xb0a1)
				return TRUE;
			else
				pstr+=2;
		}
		else
		{
			pstr++;
		}
	}

	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL IsSpecialCharacter(char* szCharacterName)
{
#if IS_KOREA_LOCALIZING()
	return IsSpecialCharacterKor(szCharacterName);
#elif IS_CHINA_LOCALIZING()
	return IsSpecialCharacterChn(szCharacterName);
#elif IS_TAIWAN_LOCALIZING()
	//return FALSE;		// Ư������ üũ�� ���д�. // �븸 ��û �����̿���
	return __IsSpecialCharacter(szCharacterName);
						// ����� �� Ư������ üũ �Լ��� �����ϴ���
						// �ƴ� ����üũ�� �ٽ��ؾ��Ѵ�.
						// comment by seven
#else
	return __IsSpecialCharacter(szCharacterName);
#endif
}