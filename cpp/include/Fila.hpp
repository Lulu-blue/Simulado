#pragma once
template <typename T>

class Fila
{
    public:
        virtual ~Fila() {}
        virtual void enfileirar(T valor) = 0;
        virtual T desenfileirar() = 0;
        virtual bool vazia() const = 0;
        virtual void imprimir() const = 0;
};