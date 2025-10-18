class matF {

private:
    int rows;
    int cols;
    float** m;

public:
    
    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    float get(int r, int c) const {
        return m[r][c];
    }
    
    void set(int r, int c, float val) {
        m[r][c] = val;
    }

    matF() {
        rows = 0;
        cols = 0;
        m = nullptr;
    }

    matF(int r, int c) {
        rows = r;
        cols = c;
        m = new float*[r];
        for (int i=0; i<r; ++i) {
            m[i] = new float[c];
        }
    }

    matF(int r, int c, float val) {
        rows = r;
        cols = c;
        m = new float*[r];
        for (int i=0; i<r; ++i) {
            m[i] = new float[c];
        }
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] = val;
            }
        }
    }

    ~matF() {
        if (m) {
            for (int i=0; i<rows; ++i) {
                delete [] m[i];
            }
            delete [] m;
        }
    }

    matF(const matF& other) {

        rows = 0;
        cols = 0;
        m = nullptr;

        // Devo usare "." invece di "->" perche other è un alias
        if (!other.rows || !other.cols) {
            return;
        }

        rows = other.rows;
        cols = other.cols;
        m = new float*[rows];
        for (int i=0; i<rows; ++i) {
            m[i] = new float[cols];
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] = other.m[i][j];
            }
        }
    }

    matF& operator= (const matF& other) {

        if (this == &other) return *this;
        
        if (rows || cols) {
            for (int i=0; i<rows; ++i) {
                delete [] m[i];
            }
            delete [] m;
        }

        rows = 0;
        cols = 0;
        m = nullptr;

        if (!other.rows || !other.cols) {
            return *this;
        }
        
        rows = other.rows;
        cols = other.cols;
        m = new float*[rows];
        for (int i=0; i<rows; ++i) {
            m[i] = new float[cols];
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] = other.m[i][j];
            }
        }

        return *this;
    }

    matF operator+ (const matF& other) const {

        matF res(*this);

        if (rows!=other.rows || cols!=other.cols) {
            cerr << "error" << endl;
            return res;
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                res.m[i][j] += other.m[i][j];
            }
        }

        return res;
    }

    matF operator- (const matF& other) const {

        matF res(*this);

        if (rows!=other.rows || cols!=other.cols) {
            cerr << "error" << endl;
            return res;
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                res.m[i][j] -= other.m[i][j];
            }
        }

        return res;
    }

    matF operator* (float mult) const {

        matF res(*this);

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                res.m[i][j] *= mult;
            }
        }

        return res;
    }

    matF operator/ (float div) const {
       if (div == 0) {
           cerr << "Division by zero!" << endl;
           return matF();
       }
       matF res(*this);
       for (int i=0; i<rows; ++i) {
           for (int j=0; j<cols; ++j) {
               res.m[i][j] /= div;
           }
       }
       return res;
   }

    matF matmul (const matF& mat1, const matF& mat2) const {

        matF res(mat1.rows, mat2.cols);

        if (mat1.cols != mat2.rows) {
            cerr << "error" << endl;
            return res;
        }
        
        for (int i=0; i<mat1.rows; ++i) {
            for (int j=0; j<mat2.cols; ++j) {
                
                res.m[i][j] = 0;
                
                for (int k=0; k<mat1.cols; ++k) {
                    res.m[i][j] += mat1.m[i][k] * mat2.m[k][j];
                }
            }
        }

        return res;

    }

    matF& operator+= (float add) {

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] += add;
            }
        }

        return *this;
    }

    matF& operator-= (float sub) {

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] -= sub;
            }
        }
        
        return *this;
    }

    matF& operator*= (float mult) {

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] *= mult;
            }
        }

        return *this;
    }
    
    matF& operator/= (float mult) {

        if (!mult) {
            return *this;
        }

        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                m[i][j] /= mult;
            }
        }

        return *this;
    }

    float* operator[] (int i) {
       return m[i];  // Permette mat[i][j] = valore;
    }
};
