#include <stdint.h>
#include <iostream>



class String {
private:
	uint32_t capacity;
	uint32_t len;
	char* s;
	uint32_t stringlen(const char* str) {
		uint32_t count = 0;
		while (*str++ != '\0')
			count++;
		return count;
	}
public:
	String();
	String(const char str[]);
	
	String(const char str[], uint32_t mult);
	~String();

	//copy constructor
	String(const String& orig);
	String& operator =(const String& orig);
    String& operator += (const String& add);
    String substring(uint32_t a, uint32_t b)const;
	char  operator [](const uint32_t pos)const;
	char& operator [](uint32_t pos);
    String replace(const char& a, const char& b)const;
    uint32_t length()const;
    String insert(uint32_t num, const String& add);
    friend String operator + (String&a, const String&b);
    
    friend std::ostream& operator<<(std::ostream& s, const String& str);
};
