#include "../../StdAfx.h"
#include "BaseMath.h"


namespace BaseMath
{
// This table only works on Little Endian(Byte Order) machine.
const unsigned short m_FastHeToBi[0x100] = {
	0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 
	0x3830, 0x3930, 0x4130, 0x4230, 0x4330, 0x4430, 0x4530, 0x4630, 
	0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731, 
	0x3831, 0x3931, 0x4131, 0x4231, 0x4331, 0x4431, 0x4531, 0x4631, 
	0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632, 0x3732, 
	0x3832, 0x3932, 0x4132, 0x4232, 0x4332, 0x4432, 0x4532, 0x4632, 
	0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533, 0x3633, 0x3733, 
	0x3833, 0x3933, 0x4133, 0x4233, 0x4333, 0x4433, 0x4533, 0x4633, 
	0x3034, 0x3134, 0x3234, 0x3334, 0x3434, 0x3534, 0x3634, 0x3734, 
	0x3834, 0x3934, 0x4134, 0x4234, 0x4334, 0x4434, 0x4534, 0x4634, 
	0x3035, 0x3135, 0x3235, 0x3335, 0x3435, 0x3535, 0x3635, 0x3735, 
	0x3835, 0x3935, 0x4135, 0x4235, 0x4335, 0x4435, 0x4535, 0x4635, 
	0x3036, 0x3136, 0x3236, 0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 
	0x3836, 0x3936, 0x4136, 0x4236, 0x4336, 0x4436, 0x4536, 0x4636, 
	0x3037, 0x3137, 0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 
	0x3837, 0x3937, 0x4137, 0x4237, 0x4337, 0x4437, 0x4537, 0x4637, 
	0x3038, 0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 
	0x3838, 0x3938, 0x4138, 0x4238, 0x4338, 0x4438, 0x4538, 0x4638, 
	0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 
	0x3839, 0x3939, 0x4139, 0x4239, 0x4339, 0x4439, 0x4539, 0x4639, 
	0x3041, 0x3141, 0x3241, 0x3341, 0x3441, 0x3541, 0x3641, 0x3741, 
	0x3841, 0x3941, 0x4141, 0x4241, 0x4341, 0x4441, 0x4541, 0x4641, 
	0x3042, 0x3142, 0x3242, 0x3342, 0x3442, 0x3542, 0x3642, 0x3742, 
	0x3842, 0x3942, 0x4142, 0x4242, 0x4342, 0x4442, 0x4542, 0x4642, 
	0x3043, 0x3143, 0x3243, 0x3343, 0x3443, 0x3543, 0x3643, 0x3743, 
	0x3843, 0x3943, 0x4143, 0x4243, 0x4343, 0x4443, 0x4543, 0x4643, 
	0x3044, 0x3144, 0x3244, 0x3344, 0x3444, 0x3544, 0x3644, 0x3744, 
	0x3844, 0x3944, 0x4144, 0x4244, 0x4344, 0x4444, 0x4544, 0x4644, 
	0x3045, 0x3145, 0x3245, 0x3345, 0x3445, 0x3545, 0x3645, 0x3745, 
	0x3845, 0x3945, 0x4145, 0x4245, 0x4345, 0x4445, 0x4545, 0x4645, 
	0x3046, 0x3146, 0x3246, 0x3346, 0x3446, 0x3546, 0x3646, 0x3746, 
	0x3846, 0x3946, 0x4146, 0x4246, 0x4346, 0x4446, 0x4546, 0x4646, 
};

WORD CosDat[]=
{
      0x07FA6,0x07FA1,0x07F92,0x07F79,0x07F56,0x07F29,0x07EF2,0x07EB2,	//00
      0x07E67,0x07E13,0x07DB5,0x07D4D,0x07CDB,0x07C60,0x07BDB,0x07B4C,	//01
      0x07AB4,0x07A12,0x07966,0x078B1,0x077F3,0x0772B,0x0765A,0x07580,	//02
      0x0749C,0x073B0,0x072BA,0x071BC,0x070B4,0x06FA4,0x06E8B,0x06D6A,	//03
      0x06C40,0x06B0E,0x069D3,0x06890,0x06745,0x065F1,0x06496,0x06333,	//04
      0x061C8,0x06056,0x05EDC,0x05D5B,0x05BD2,0x05A42,0x058AC,0x0570E,	//05
      0x05569,0x053BE,0x0520D,0x05054,0x04E96,0x04CD2,0x04B07,0x04937,	//06
      0x04761,0x04585,0x043A4,0x041BE,0x03FD3,0x03DE2,0x03BED,0x039F3,	//07
      0x037F5,0x035F2,0x033EB,0x031E0,0x02FD1,0x02DBE,0x02BA8,0x0298E,	//08
      0x02772,0x02552,0x0232F,0x02109,0x01EE1,0x01CB6,0x01A8A,0x0185B,	//09
      0x0162A,0x013F8,0x011C3,0x00F8E,0x00D57,0x00B20,0x008E7,0x006AE,	//00
      0x00474,0x0023A,0x00000,0x0FDC5,0x0FB8B,0x0F951,0x0F718,0x0F4DF,	//01
      0x0F2A8,0x0F071,0x0EE3C,0x0EC08,0x0E9D5,0x0E7A4,0x0E575,0x0E349,	//02
      0x0E11E,0x0DEF6,0x0DCD0,0x0DAAD,0x0D88D,0x0D671,0x0D457,0x0D241,	//03
      0x0D02E,0x0CE1F,0x0CC14,0x0CA0D,0x0C80A,0x0C60C,0x0C412,0x0C21D,	//04
      0x0C02D,0x0BE41,0x0BC5B,0x0BA7A,0x0B89E,0x0B6C8,0x0B4F8,0x0B32D,	//05
      0x0B169,0x0AFAB,0x0ADF3,0x0AC41,0x0AA96,0x0A8F1,0x0A753,0x0A5BD,	//06
      0x0A42D,0x0A2A4,0x0A123,0x09FA9,0x09E37,0x09CCC,0x09B69,0x09A0E,	//07
      0x098BA,0x0976F,0x0962C,0x094F1,0x093BF,0x09295,0x09174,0x0905B,	//08
      0x08F4B,0x08E43,0x08D45,0x08C4F,0x08B63,0x08A7F,0x089A5,0x088D4,	//09
      0x0880C,0x0874E,0x08699,0x085ED,0x0854B,0x084B3,0x08424,0x0839F,	//00
      0x08324,0x082B2,0x0824A,0x081EC,0x08198,0x0814D,0x0810D,0x080D6,	//01
      0x080A9,0x08086,0x0806D,0x0805E,0x0805A,0x0805E,0x0806D,0x08086,	//02
      0x080A9,0x080D6,0x0810D,0x0814D,0x08198,0x081EC,0x0824A,0x082B2,	//03
      0x08324,0x0839F,0x08424,0x084B3,0x0854B,0x085ED,0x08699,0x0874E,	//04
      0x0880C,0x088D4,0x089A5,0x08A7F,0x08B63,0x08C4F,0x08D45,0x08E43,	//05
      0x08F4A,0x0905B,0x09173,0x09295,0x093BF,0x094F1,0x0962C,0x0976F,	//06
      0x098BA,0x09A0E,0x09B69,0x09CCC,0x09E37,0x09FA9,0x0A123,0x0A2A4,	//07
      0x0A42D,0x0A5BD,0x0A753,0x0A8F1,0x0AA96,0x0AC41,0x0ADF2,0x0AFAA,	//08
      0x0B169,0x0B32D,0x0B4F8,0x0B6C8,0x0B89E,0x0BA7A,0x0BC5B,0x0BE41,	//09
      0x0C02C,0x0C21D,0x0C412,0x0C60C,0x0C80A,0x0CA0D,0x0CC14,0x0CE1F,	//00
      0x0D02E,0x0D241,0x0D457,0x0D670,0x0D88D,0x0DAAD,0x0DCD0,0x0DEF6,	//01
      0x0E11E,0x0E348,0x0E575,0x0E7A4,0x0E9D5,0x0EC07,0x0EE3B,0x0F071,	//02
      0x0F2A8,0x0F4DF,0x0F718,0x0F951,0x0FB8B,0x0FDC5,0x0FFFF,0x0023A,	//03
      0x00474,0x006AE,0x008E7,0x00B1F,0x00D57,0x00F8E,0x011C3,0x013F7,	//04
      0x0162A,0x0185B,0x01A8A,0x01CB6,0x01EE1,0x02109,0x0232F,0x02551,	//05
      0x02771,0x0298E,0x02BA8,0x02DBE,0x02FD1,0x031E0,0x033EB,0x035F2,	//06
      0x037F4,0x039F3,0x03BED,0x03DE2,0x03FD2,0x041BE,0x043A4,0x04585,	//07
      0x04761,0x04937,0x04B07,0x04CD1,0x04E96,0x05054,0x0520C,0x053BE,	//08
      0x05569,0x0570E,0x058AB,0x05A42,0x05BD2,0x05D5B,0x05EDC,0x06056,	//09
      0x061C8,0x06333,0x06496,0x065F1,0x06744,0x06890,0x069D3,0x06B0D,
      0x06C40,0x06D6A,0x06E8B,0x06FA4,0x070B4,0x071BC,0x072BA,0x073B0,
      0x0749C,0x07580,0x0765A,0x0772B,0x077F3,0x078B1,0x07966,0x07A12,
      0x07AB4,0x07B4C,0x07BDB,0x07C60,0x07CDB,0x07D4D,0x07DB5,0x07E13,
      0x07E67,0x07EB2,0x07EF2,0x07F29,0x07F56,0x07F79,0x07F92,0x07FA1,
};

WORD SinDat[]=
{
      0x00000,0x0023A,0x00474,0x006AE,0x008E7,0x00B20,0x00D57,0x00F8E,
      0x011C3,0x013F7,0x0162A,0x0185B,0x01A8A,0x01CB6,0x01EE1,0x02109,
      0x0232F,0x02552,0x02772,0x0298E,0x02BA8,0x02DBE,0x02FD1,0x031E0,
      0x033EB,0x035F2,0x037F5,0x039F3,0x03BED,0x03DE2,0x03FD2,0x041BE,
      0x043A4,0x04585,0x04761,0x04937,0x04B07,0x04CD2,0x04E96,0x05054,
      0x0520C,0x053BE,0x05569,0x0570E,0x058AC,0x05A42,0x05BD2,0x05D5B,
      0x05EDC,0x06056,0x061C8,0x06333,0x06496,0x065F1,0x06745,0x06890,
      0x069D3,0x06B0E,0x06C40,0x06D6A,0x06E8B,0x06FA4,0x070B4,0x071BC,
      0x072BA,0x073B0,0x0749C,0x07580,0x0765A,0x0772B,0x077F3,0x078B1,
      0x07966,0x07A12,0x07AB4,0x07B4C,0x07BDB,0x07C60,0x07CDB,0x07D4D,
      0x07DB5,0x07E13,0x07E67,0x07EB2,0x07EF2,0x07F29,0x07F56,0x07F79,
      0x07F92,0x07FA1,0x07FA5,0x07FA1,0x07F92,0x07F79,0x07F56,0x07F29,
      0x07EF2,0x07EB2,0x07E67,0x07E13,0x07DB5,0x07D4D,0x07CDB,0x07C60,
      0x07BDB,0x07B4C,0x07AB4,0x07A12,0x07966,0x078B1,0x077F3,0x0772B,
      0x0765A,0x07580,0x0749C,0x073B0,0x072BA,0x071BC,0x070B4,0x06FA4,
      0x06E8C,0x06D6A,0x06C40,0x06B0E,0x069D3,0x06890,0x06745,0x065F1,
      0x06496,0x06333,0x061C8,0x06056,0x05EDC,0x05D5B,0x05BD2,0x05A42,
      0x058AC,0x0570E,0x05569,0x053BE,0x0520D,0x05054,0x04E96,0x04CD2,
      0x04B07,0x04937,0x04761,0x04585,0x043A4,0x041BE,0x03FD3,0x03DE2,
      0x03BED,0x039F3,0x037F5,0x035F2,0x033EB,0x031E0,0x02FD1,0x02DBE,
      0x02BA8,0x0298E,0x02772,0x02552,0x0232F,0x02109,0x01EE1,0x01CB7,
      0x01A8A,0x0185B,0x0162A,0x013F8,0x011C3,0x00F8E,0x00D57,0x00B20,
      0x008E7,0x006AE,0x00474,0x0023A,0x00000,0x0FDC5,0x0FB8B,0x0F951,
      0x0F718,0x0F4E0,0x0F2A8,0x0F071,0x0EE3C,0x0EC08,0x0E9D5,0x0E7A4,
      0x0E575,0x0E349,0x0E11E,0x0DEF6,0x0DCD0,0x0DAAD,0x0D88E,0x0D671,
      0x0D457,0x0D241,0x0D02E,0x0CE1F,0x0CC14,0x0CA0D,0x0C80A,0x0C60C,
      0x0C412,0x0C21D,0x0C02D,0x0BE41,0x0BC5B,0x0BA7A,0x0B89E,0x0B6C8,
      0x0B4F8,0x0B32D,0x0B169,0x0AFAB,0x0ADF3,0x0AC41,0x0AA96,0x0A8F1,
      0x0A754,0x0A5BD,0x0A42D,0x0A2A4,0x0A123,0x09FA9,0x09E37,0x09CCC,
      0x09B69,0x09A0E,0x098BB,0x0976F,0x0962C,0x094F1,0x093BF,0x09295,
      0x09174,0x0905B,0x08F4B,0x08E43,0x08D45,0x08C4F,0x08B63,0x08A7F,
      0x089A5,0x088D4,0x0880C,0x0874E,0x08699,0x085ED,0x0854B,0x084B3,
      0x08424,0x0839F,0x08324,0x082B2,0x0824A,0x081EC,0x08198,0x0814D,
      0x0810D,0x080D6,0x080A9,0x08086,0x0806D,0x0805E,0x0805A,0x0805E,
      0x0806D,0x08086,0x080A9,0x080D6,0x0810D,0x0814D,0x08198,0x081EC,
      0x0824A,0x082B2,0x08324,0x0839F,0x08424,0x084B3,0x0854B,0x085ED,
      0x08699,0x0874E,0x0880C,0x088D4,0x089A5,0x08A7F,0x08B63,0x08C4F,
      0x08D45,0x08E43,0x08F4A,0x0905B,0x09173,0x09295,0x093BF,0x094F1,
      0x0962C,0x0976F,0x098BA,0x09A0E,0x09B69,0x09CCC,0x09E37,0x09FA9,
      0x0A123,0x0A2A4,0x0A42D,0x0A5BD,0x0A753,0x0A8F1,0x0AA96,0x0AC41,
      0x0ADF2,0x0AFAA,0x0B169,0x0B32D,0x0B4F8,0x0B6C8,0x0B89E,0x0BA7A,
      0x0BC5B,0x0BE41,0x0C02C,0x0C21D,0x0C412,0x0C60C,0x0C80A,0x0CA0D,
      0x0CC14,0x0CE1F,0x0D02E,0x0D241,0x0D457,0x0D670,0x0D88D,0x0DAAD,
      0x0DCD0,0x0DEF6,0x0E11E,0x0E348,0x0E575,0x0E7A4,0x0E9D5,0x0EC07,
      0x0EE3B,0x0F071,0x0F2A8,0x0F4DF,0x0F718,0x0F951,0x0FB8B,0x0FDC5,
};

	const char*	PrefixOfHexadecimal		= "0x";

};
