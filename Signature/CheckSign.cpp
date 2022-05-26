#include "CheckSign.h"
#include <pcre2.h>

UnicodeString CheckSign::CheckSigns(BYTE *dataBuffer){

	byte jpeg[4]={255, 216, 255,224};
	byte MSOfiice[11]={95,84,121,112,101,115,93,46,120,109,108};
	byte zip[4]={80,75,3,4};
	byte photoshop[12]={56,66,80,83,0,1,0,0,0,0,0,0};
	byte png[8]={137,80,78,71,13,10,26,10};



	 if(dataBuffer[0]==photoshop[0])
		{if(Check(0,photoshop,12,dataBuffer))
			return "Photoshop";
		}
	 if(dataBuffer[0]==png[0])
		if(Check(0,png,8,dataBuffer))
			return "PNG";
	 if(dataBuffer[0]==jpeg[0])
		if(Check(0,jpeg,4,dataBuffer))
			return "JPEG";

	for(int i=0; i<512; i++)
	{
	 if(dataBuffer[i]==MSOfiice[0])
		if(Check(i,MSOfiice,11,dataBuffer))
			return "MS Office 2007+";
	}

	if(dataBuffer[0]==zip[0])
		if(Check(0,zip,4,dataBuffer))
			return "ZIP";

	return "NON";
}

bool CheckSign::Check(int pos,BYTE sign[],int length,BYTE *dataBuffer){
	for(int j=0; j<length;j++)
	{
	  if(sign[j]!=dataBuffer[pos+j])
		return false;
	}
    return true;
}
//MS Office 2007+	docx;xlsx;pptx	_Types\]\.xml	38	~14		g
//JPEG	JPG;jpeg;jpe;thm;mpo	\xFF\xD8\xFF[\xC0\xC4\xDB\xDD\xE0-\xE5\xE7\xE8\xEA-\xEE\xFE]	0	~1	2097152/33554432	e
//Zip Archive	zip;jar;xps;apk;pages	PK\x03\x04|PK00|PK\x05\x06	0	~14	4194304/536870912	gGE
//photoshop 8BPS\x00\x01\x00\x00\x00\x00\x00\x00
//PNG	png	\x89PNG\x0D\x0A\x1A\x0A	0	~6		e

bool CheckSign::TEST(BYTE *dataBuffer) {

	String str1="";

	for(int i=0; i<12;i++)
	{
	  str1+=(char)dataBuffer[i];
	}


  PCRE2_SPTR subject = (PCRE2_SPTR) str1.c_str();
  PCRE2_SPTR pattern = (PCRE2_SPTR) "\\x38\\x42\\x50\\x53\\x00\\x01\\x00\\x00\\x00\\x00\\x00\\x00";
  int errorcode;
  PCRE2_SIZE erroroffset;
  pcre2_code *re = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED,PCRE2_UTF, &errorcode,
                                 &erroroffset, NULL);
  if (re) {
	uint32_t groupcount = 0;
	pcre2_pattern_info(re, PCRE2_INFO_BACKREFMAX, &groupcount);
	pcre2_match_data *match_data = pcre2_match_data_create_from_pattern(re, NULL);
	uint32_t options_exec = PCRE2_NOTEMPTY;
	//PCRE2_SIZE subjectlen = strlen((const char *) subject);

	errorcode = pcre2_match(re, subject, 3, 0, options_exec, match_data, NULL);

    pcre2_match_data_free(match_data);
	pcre2_code_free(re);
    return true;
  } else {
    // Syntax error in the regular expression at erroroffset
    PCRE2_UCHAR error[256];
	pcre2_get_error_message(errorcode, error, sizeof(error));
	return false;
	}

}


