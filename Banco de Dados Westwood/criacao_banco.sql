-- =========================================
-- CRIAÇÃO DO BANCO DE DADOS - LOJA DE ROUPAS
-- ORACLE SQL
-- =========================================

-- =========================================
-- TABELA CLIENTE
-- =========================================

CREATE TABLE Cliente (
    id_cliente NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    nome VARCHAR2(100) NOT NULL,
    email VARCHAR2(100),
    telefone VARCHAR2(20),
    cpf VARCHAR2(14) UNIQUE,
    
    -- ENDEREÇO
    rua VARCHAR2(100),
    numero VARCHAR2(10),
    bairro VARCHAR2(50),
    cidade VARCHAR2(50),
    cep VARCHAR2(10)
);

-- =========================================
-- TABELA CATEGORIA
-- =========================================

CREATE TABLE Categoria (
    id_categoria NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    nome_categoria VARCHAR2(50) NOT NULL
);

-- =========================================
-- TABELA PRODUTO
-- =========================================

CREATE TABLE Produto (
    id_produto NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    nome VARCHAR2(100) NOT NULL,
    descricao VARCHAR2(200),
    preco NUMBER(10,2) NOT NULL,
    estoque NUMBER NOT NULL,
    
    -- ROUPAS
    tamanho VARCHAR2(5),
    cor VARCHAR2(30),
    
    id_categoria NUMBER,
    
    CONSTRAINT fk_categoria
        FOREIGN KEY (id_categoria)
        REFERENCES Categoria(id_categoria)
);

-- =========================================
-- TABELA PEDIDO
-- =========================================

CREATE TABLE Pedido (
    id_pedido NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    
    data_pedido TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    
    valor_total NUMBER(10,2),
    
    status VARCHAR2(30),
    
    id_cliente NUMBER,
    
    CONSTRAINT fk_cliente
        FOREIGN KEY (id_cliente)
        REFERENCES Cliente(id_cliente)
);

-- =========================================
-- TABELA ITEM_PEDIDO
-- =========================================

CREATE TABLE Item_Pedido (
    id_item NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    
    quantidade NUMBER NOT NULL,
    preco_unitario NUMBER(10,2) NOT NULL,
    
    id_pedido NUMBER,
    id_produto NUMBER,
    
    CONSTRAINT fk_pedido
        FOREIGN KEY (id_pedido)
        REFERENCES Pedido(id_pedido),
        
    CONSTRAINT fk_produto
        FOREIGN KEY (id_produto)
        REFERENCES Produto(id_produto)
);

-- =========================================
-- TABELA PAGAMENTO
-- =========================================

CREATE TABLE Pagamento (
    id_pagamento NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    
    tipo_pagamento VARCHAR2(50),
    status VARCHAR2(30),
    
    id_pedido NUMBER UNIQUE,
    
    CONSTRAINT fk_pagamento_pedido
        FOREIGN KEY (id_pedido)
        REFERENCES Pedido(id_pedido)
);