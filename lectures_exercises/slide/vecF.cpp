#include <iostream>
using namespace std;

class VecF {
private:
    int size; 
    float* v;

public:
    
    float get(int i) {
        return v[i];
    }
    
    void set(int i, float f) {
        v[i]=f;
    }

    VecF() {
        size=0; 
        v=nullptr;
    }

    VecF(int size) {
        this->size=size; 
        v=new float[size];
    }

    ~VecF() {
        if (size) {
            delete [] v;
        }
    }

    VecF(const VecF& other) {
        size = 0;
        v = nullptr;

        if (!other.size) return;
        
        size = other.size;
        v = new float[size];

        for (int i=0; i<size; ++i) {
            v[i] = other.v[i];
        }
    }

    VecF& operator= (const VecF& other) {

        if (&other == this) return *this;

        if (size) delete [] v;
        
        size = 0;
        v = nullptr; 
    
        if (!other.size) return *this;

        size = other.size;
        v = new float[size];
    
        for (int i=0; i<size; ++i) {
            v[i]=other.v[i];
        }

        return *this;
    }

    VecF operator+ (const VecF& other) const {

        VecF result(*this);

        if (size != other.size) {
            cerr << "error" << endl;
            return result;
        }

        for (int i=0; i<size; ++i) {
            result.v[i]+=other.v[i];
        }

        return result;
    }

    VecF operator- (const VecF& other) const {

        VecF result(*this);

        if (size != other.size) {
            cerr << "error" << endl;
            return result;
        }

        for (int i=0; i<size; ++i) {
            result.v[i]-=other.v[i];
        }

        return result;
    }

    VecF operator* (float mult) const {
        
        VecF result(*this);

        for (int i=0; i<size; ++i) {
            result.v[i]*=mult;
        }

        return result;
    }

    VecF operator/ (float mult) const {
        
        VecF result(*this);

        if (mult == 0) {
            cerr << "Division by zero!" << endl;
            return result;
        }

        for (int i=0; i<size; ++i) {
            result.v[i]/=mult;
        }

        return result;
    }

    VecF operator* (const VecF& other) const {

        VecF result(*this);

        if (size!=other.size) {
            cerr << "error" << endl;
            return result;
        }

        for (int i=0; i<size; ++i) {
            result.v[i]*=other.v[i];
        }

        return result;
    }

    VecF operator/ (const VecF& other) const {

        VecF result(*this);

        if (size!=other.size) {
            cerr << "error" << endl;
            return result;
        }

        for (int i=0; i<size; ++i) {

            if (other.v[i] == 0) {
                cerr << "Division by zero!" << endl;
                return result;
            }

            result.v[i]/=other.v[i];
        }

        return result;
    }

    VecF& operator+= (const VecF& other) {

        if (size != other.size) {
            cerr << "error" << endl;
            return *this;
        }

        for (int i=0; i<size; ++i) {
            v[i]+=other.v[i];
        }

        return *this;
    }

    VecF& operator-= (const VecF& other) {

        if (size != other.size) {
            cerr << "error" << endl;
            return *this;
        }

        for (int i=0; i<size; ++i) {
            v[i]-=other.v[i];
        }

        return *this;
    }

    VecF& operator*= (float mult) {

        for (int i=0; i<size; ++i) {
            v[i]*=mult;
        }

        return *this;
    }

    VecF& operator*= (const VecF& other) {

        if (size != other.size) {
            cerr << "error" << endl;
            return *this;
        }

        for (int i=0; i<size; ++i) {
            v[i]*=other.v[i];
        }

        return *this;
    }

    VecF& operator/= (float mult) {

        if (mult == 0) {
            cerr << "Division by zero!" << endl;
            return *this;
        }

        for (int i=0; i<size; ++i) {
            v[i]/=mult;
        }

        return *this;
    }

    VecF& operator/= (const VecF& other) {

        if (size != other.size) {
            cerr << "error" << endl;
            return *this;
        }

        for (int i=0; i<size; ++i) {
            
            if (other.v[i] == 0) {
                cerr << "Division by zero!" << endl;
                return *this;
            }

            v[i]/=other.v[i];
        }

        return *this;
    }
};