# Instruções de Compilação e Execução do Projeto por Linguagem

Este `README` fornece um guia sobre como compilar os códigos de ordenação

---

## 1. C

**Pré-requisitos:** Compilador C .

1.  **Navegue até a pasta do projeto C:**
    ```bash
    cd c/
    ```
2.  **Limpar o projeto:**
    Remove arquivos compilados (`.o`, executáveis).
    ```bash
    make clean
    ```
3.  **Compilar o código:**
    Compila os arquivos `.c` para gerar o executável.
    ```bash
    make
    ```
4.  **Executar o programa:**
    Roda o executável compilado.
    ```bash
    make run
    ```

---

## 2. C++

**Pré-requisitos:** Compilador C++.

1.  **Navegue até a pasta do projeto C++:**
    ```bash
    cd cpp/
    ```
2.  **Limpar o projeto:**
    Remove arquivos compilados (`.o`, executáveis).
    ```bash
    make clean
    ```
3.  **Compilar o código:**
    Compila os arquivos `.cpp` para gerar o executável.
    ```bash
    make
    ```
4.  **Executar o programa:**
    Roda o executável compilado.
    ```bash
    make run
    ```
  
---

## 3. Python


**Pré-requisitos:** Interpretador Python.

1.  **Navegue até a pasta do projeto Python:**
    ```bash
    cd python/
    ```
2.  **Limpar o projeto:**
    Remove caches (`__pycache__`), arquivos de log, etc.
    ```bash
    make clean
    ```
3.  **Preparar/Executar (make):**
    Este alvo pode ser usado para instalar dependências ou executar o script principal.
    ```bash
    make
    ```
4.  **Executar o programa:**
    Roda o script Python principal.
    ```bash
    make run
    ```

---

## 4. Java

**Pré-requisitos:** Java Development Kit (JDK) instalado.

1.  **Navegue até a pasta do projeto Java:**
    ```bash
    cd java/
    ```
2.  **Limpar o projeto:**
    Remove arquivos `.class` e outros gerados.
    ```bash
    make clean
    ```
3.  **Compilar o código:**
    Compila os arquivos `.java` para gerar os `.class`.
    ```bash
    make
    ```
4.  **Executar o programa:**
    Roda a aplicação Java a partir da classe principal.
    ```bash
    make run
    ```
  
---

## 5. Ruby


**Pré-requisitos:** Interpretador Ruby.

1.  **Navegue até a pasta do projeto Ruby:**
    ```bash
    cd ruby/
    ```
2.  **executar:**
   ### Executa diretamente o arquivo principal
   
   ```bash
    ruby main.rb

  
  
