#include <iostream>
#include <cstdlib>

template <typename T>
class CVector {
private:
    int m_nMax;    
    int m_nDelta;
public:
    int m_nCount = 0;   
    T* m_pVect;     

    CVector(int delta = 10) {
        m_nMax = 10;
        m_nDelta = delta;
        m_pVect = static_cast<T*>(std::malloc(sizeof(T) * m_nMax));
    }

    ~CVector() {
        std::free(m_pVect);  
    }

    void Resize() {
        m_pVect = static_cast<T*>(std::realloc(m_pVect, sizeof(T) * (m_nMax + m_nDelta)));
        m_nMax += m_nDelta;
    }

    void Insert(T elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    void Print() {
        for (int i = 0; i < m_nCount; ++i) {
            std::cout << m_pVect[i] << std::endl;
        }
    }
};

int main() {
    CVector<int> myVector(10);

    myVector.Insert(30);
    myVector.Insert(50);
    myVector.Insert(100);

    // Imprimir los elementos
    std::cout << "Abstrac Data Types Insert Test" << std::endl;
    std::cout << "Vector:" << std::endl;
    myVector.Print();

    return 0;
}
