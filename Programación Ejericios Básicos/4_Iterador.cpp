#include <iostream>
#include <vector>


class CMyComplexDataStructure {
private:
    std::vector<float> m_container;

public:
    void Insert(float fVal) {
        m_container.push_back(fVal);
    }

    template <typename objclass>
    void sumone(objclass funobj) {
        for (auto iter = m_container.begin(); iter != m_container.end(); ++iter) {
            funobj(*iter);
        }
    }
    void Print()
    {
        for (auto iter = m_container.begin(); iter != m_container.end(); ++iter) {
            std::cout << *iter << std::endl;
        }
    }
};

template <typename objclass>
class funcobjclass {
public:
    void operator()(objclass& objinstance) {
        objinstance++;
    }
};

int main(int argc, char* argv[]) {
    CMyComplexDataStructure ds;
    std::cout << "Design Patterns Insert Test" << std::endl;
    std::cout << "Vector:" << std::endl;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);
    ds.Print();
    funcobjclass<float> x;
    ds.sumone(x);
    std::cout << "Despues de la funcion sumeone con operator" << std::endl;
    ds.Print();
    return 0;
}