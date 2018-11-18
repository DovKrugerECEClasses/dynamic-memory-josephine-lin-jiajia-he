#include "String.hh"

String::String():len(0), s(nullptr){}

String::String(const char str[]):len(strlen(str)), s(new char[len]){
    for(int i=0;i<len;i++){
        s[i]=str[i];
    }
}
	
String::String(const char str[], uint32_t mult):len(strlen(str)*mult), s(new char[len]){
    uint32_t strsize = len/mult;
    int c=0;
    for(int j=0;j<mult;j++)
        for(int i=0;i<strsize;i++,c++)
            s[c]=str[i];
}

String::~String(){ delete [] s; }

	//copy constructor
String::String(const String& orig):len(orig.len),s(new char[len]){
    uint64_t* src=(uint64_t*)orig.s;
    uint64_t* dest=(uint64_t*)s;
    uint32_t count;
    for(count=len; count>8;count-=8)
        *dest++ = *src++;
    char* pdest=(char*)dest;
    char* psrc=(char*)src;
    for(;count>0;count--)
        *pdest++ = *src++;
}
String& String::operator =(const String& orig) {
    String copy(orig);//copy here is the variable name
    len=orig.len;
    swap(s,copy.s);
    return *this;
}

String& String::operator += (const String& add){
    uint32_t lengh=len+add.len;
    len=lengh;
    for(uint32_t i=len-add.len;i<len;i++)
        s[i]=add.s[i-(len-add.len)];
    return *this;
}

String String::substring(uint32_t a, uint32_t b)const {
    String copy(*this);
    copy.len=b;
    for(uint32_t i=a;i<a+b;i++)
        copy.s[i-a]=s[i];        
    return copy;
}

char String::operator [](const uint32_t pos)const{
    return s[pos];
}

char& String::operator [](uint32_t pos) { return s[pos];}

String String::replace(const char& a, const char& b)const{
    for(uint32_t i=0;i<len;i++)
        if(s[i]==a)
            s[i]=b;
    return *this;
}

uint32_t String::length()const{
    return len;
}

String String::insert(uint32_t num, const String& add){
    len=add.len+len;     
    for(uint32_t i=num+add.len;i<len;i++)
        s[i]=s[i-num];
    for(uint32_t i=num;i<num+add.len;i++)
        s[i]=add.s[i-num];
    return *this;
}

friend String String::operator + (String&a, const String&b){
    a.len=a.len+b.len;
    for(uint32_t i=a.len-b.len;i<a.len;i++)
	a.s[i]=b.s[i-a.len+b.len];
    return a;
}

friend ostream& operator<<(ostream& s, const String& str) {
    for(uint32_t i=0;i<str.len;i++) {
        s<<str[i];
    }
    return s;
}

	
