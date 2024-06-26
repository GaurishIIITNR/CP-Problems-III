// select votes
// from results
// where id in(
//     select id
//     from candidates
// where gender = 'F'
// and age < 50
//     );



// SELECT TOP 1 cust.NAME, ord.PRICE
// FROM CUSTOMERS cust INNER JOIN ORDERS ord
// ON cust.ORDER_ID = ord.ID
// WHERE ord.ORDER_DATE <= DATEADD(year, 10, (SELECT MIN(ORDER_DATE) FROM ORDERS))
// ORDER BY ord.PRICE DESC

