#pragma once

#include <iostream>

template <typename T>
class GrowArray{
private:
    T* data;
    int used;
    int capacity;
    void checkGrow(){
        if(used<capacity)
            return;
        T* old = data;
        data =new T[used*2];
        for(int i=0;i<used;i++){
            data[i]=old[i];
        }
        used ++;
    }
public:
    GrowArray():used(0), capacity(0), data(nullptr){}
    GrowArray(int initialCapacity) : used(0), capacity(initialCapacity), data(new T[used]){}
    ~GrowArray(){delete [] data;}
    void addEnd(const T& v){
        checkGrow();
        data[used-1]=v;
    }

    T removeEnd(){
        used--;
        return data[used];
    }

    T operator =(const T& a){
        for(int i=0;i < a.used;i++){
            this->data[i]=a.data[i];
        }
    }

    T& operator[](int i) {
        return data[i];
    }

    T operator[](int i)const {
        return data[i];
    }

    friend std::ostream& operator << (std::ostream& s, const GrowArray<T>& list){
        for(int i=0;i<list.used;i++){
            s<<list[i]<< ' ';
        }
        return s;
    }
};
