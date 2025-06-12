#pragma once
#include "Fila.hpp"
#include <vector>

template <typename T>

class FilaVetor : public Fila<T> 
{
    private:
        std::vector<T> dados;
        
    public:
        void enfileirar(T valor) override {dados.push_back(valor);}

        T desenfileirar() override
        {
            if (vazia()) throw std::runtime_error("Fila vazia!");
            T valor = dados.front();
            dados.erase(dados.begin());
            return valor;
        }

        bool vazia() const override {return dados.empty();}

        void imprimir() const override
        {
            for (const auto& item : dados)
            {std::cout << item << " ";}
            std::cout << std::endl;
        }
};