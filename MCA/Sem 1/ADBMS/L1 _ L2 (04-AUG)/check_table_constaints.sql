/* To check the constraint names associated with a table, user_cons_columns is a system table */
select owner, constraint_name, column_name from user_cons_columns where table_name='STUDENTS';