#include <iostream>
#include <cstdlib> 


struct Vector
{
    int* m_pVect; // Puntero al búfer
    int m_nCount; 
    int m_nMax;   
    int m_nDelta; 
};

void Resize(Vector* pThis)
{
    pThis->m_pVect = static_cast<int*>(std::realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta)));
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) 
        Resize(pThis); 
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Print(Vector* pThis)
{
    for (int i = 0; i < pThis->m_nCount; ++i) 
    {
        std::cout << pThis->m_pVect[i] << std::endl;
    }
}

int main()
{
    Vector myVector;
    myVector.m_nCount = 0;
    myVector.m_nMax = 10; 
    myVector.m_nDelta = 5; 


    myVector.m_pVect = static_cast<int*>(std::malloc(sizeof(int) * myVector.m_nMax));

    Insert(&myVector, 30);
    Insert(&myVector, 50);
    Insert(&myVector, 100);

    // Test
    std::cout << "Modular Insert Test" << std::endl;
    std::cout << "Vector:" << std::endl;

    Print(&myVector);

    return 0;
}
