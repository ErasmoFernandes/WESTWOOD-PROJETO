-- =========================================
-- CONSULTAS - LOJA DE ROUPAS
-- ORACLE SQL
-- =========================================

-- =========================================
-- LISTAR CLIENTES
-- =========================================

SELECT * FROM Cliente;

-- =========================================
-- LISTAR PRODUTOS
-- =========================================

SELECT
    nome,
    preco,
    estoque,
    tamanho,
    cor
FROM Produto;

-- =========================================
-- PEDIDOS COM CLIENTES
-- =========================================

SELECT
    p.id_pedido,
    c.nome AS cliente,
    p.data_pedido,
    p.valor_total,
    p.status
FROM Pedido p
JOIN Cliente c
ON p.id_cliente = c.id_cliente;

-- =========================================
-- ITENS DOS PEDIDOS
-- =========================================

SELECT
    pe.id_pedido,
    pr.nome AS produto,
    ip.quantidade,
    ip.preco_unitario
FROM Item_Pedido ip
JOIN Pedido pe
ON ip.id_pedido = pe.id_pedido
JOIN Produto pr
ON ip.id_produto = pr.id_produto;

-- =========================================
-- PAGAMENTOS
-- =========================================

SELECT
    pe.id_pedido,
    pa.tipo_pagamento,
    pa.status
FROM Pagamento pa
JOIN Pedido pe
ON pa.id_pedido = pe.id_pedido;

-- =========================================
-- ATUALIZAÇÃO AUTOMÁTICA DE ESTOQUE
-- =========================================

UPDATE Produto
SET estoque = estoque - 1
WHERE id_produto = 1;

-- =========================================
-- CÁLCULO DO VALOR TOTAL DO PEDIDO
-- =========================================

SELECT
    id_pedido,
    SUM(quantidade * preco_unitario) AS total_pedido
FROM Item_Pedido
GROUP BY id_pedido;