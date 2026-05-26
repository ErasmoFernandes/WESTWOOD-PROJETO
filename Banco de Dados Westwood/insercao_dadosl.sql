-- =========================================
-- INSERÇÃO DE DADOS - LOJA DE ROUPAS
-- ORACLE SQL
-- =========================================

-- =========================================
-- INSERINDO CATEGORIAS
-- =========================================

INSERT INTO Categoria (nome_categoria)
VALUES ('Tênis');

INSERT INTO Categoria (nome_categoria)
VALUES ('Camisetas');

INSERT INTO Categoria (nome_categoria)
VALUES ('Calças');

INSERT INTO Categoria (nome_categoria)
VALUES ('Jaquetas');

INSERT INTO Categoria (nome_categoria)
VALUES ('Shorts');

-- =========================================
-- INSERINDO CLIENTES
-- =========================================

INSERT INTO Cliente (
    nome, email, telefone, cpf,
    rua, numero, bairro, cidade, cep
)
VALUES (
    'João Silva',
    'joao@gmail.com',
    '11999999999',
    '123.456.789-00',
    'Rua A',
    '100',
    'Centro',
    'São Paulo',
    '01000-000'
);

INSERT INTO Cliente (
    nome, email, telefone, cpf,
    rua, numero, bairro, cidade, cep
)
VALUES (
    'Maria Souza',
    'maria@gmail.com',
    '11988888888',
    '987.654.321-00',
    'Rua B',
    '200',
    'Moema',
    'São Paulo',
    '02000-000'
);

-- =========================================
-- INSERINDO PRODUTOS
-- =========================================

INSERT INTO Produto (
    nome, descricao, preco, estoque,
    tamanho, cor, id_categoria
)
VALUES (
    'Tênis Esportivo',
    'Tênis leve para corrida',
    250.00,
    15,
    '42',
    'Preto',
    1
);

INSERT INTO Produto (
    nome, descricao, preco, estoque,
    tamanho, cor, id_categoria
)
VALUES (
    'Camiseta Básica',
    'Algodão 100%',
    50.00,
    30,
    'M',
    'Branca',
    2
);

INSERT INTO Produto (
    nome, descricao, preco, estoque,
    tamanho, cor, id_categoria
)
VALUES (
    'Calça Jeans',
    'Modelagem slim',
    120.00,
    20,
    '40',
    'Azul',
    3
);

-- =========================================
-- INSERINDO PEDIDOS
-- =========================================

INSERT INTO Pedido (
    valor_total,
    status,
    id_cliente
)
VALUES (
    300.00,
    'Pago',
    1
);

INSERT INTO Pedido (
    valor_total,
    status,
    id_cliente
)
VALUES (
    120.00,
    'Pendente',
    2
);

-- =========================================
-- INSERINDO ITENS DO PEDIDO
-- =========================================

INSERT INTO Item_Pedido (
    quantidade,
    preco_unitario,
    id_pedido,
    id_produto
)
VALUES (
    1,
    250.00,
    1,
    1
);

INSERT INTO Item_Pedido (
    quantidade,
    preco_unitario,
    id_pedido,
    id_produto
)
VALUES (
    1,
    50.00,
    1,
    2
);

INSERT INTO Item_Pedido (
    quantidade,
    preco_unitario,
    id_pedido,
    id_produto
)
VALUES (
    1,
    120.00,
    2,
    3
);

-- =========================================
-- INSERINDO PAGAMENTOS
-- =========================================

INSERT INTO Pagamento (
    tipo_pagamento,
    status,
    id_pedido
)
VALUES (
    'Cartão',
    'Pago',
    1
);

INSERT INTO Pagamento (
    tipo_pagamento,
    status,
    id_pedido
)
VALUES (
    'Pix',
    'Pendente',
    2
);