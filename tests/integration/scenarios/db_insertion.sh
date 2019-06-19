#!/usr/bin/env bash
touch tableWithoutRows.sqlite3
sqlite3 tableWithoutRows.sqlite3 "CREATE TABLE test(id integer primary key, name text);"

touch tableWithOneRow.sqlite3
sqlite3 tableWithOneRow.sqlite3 "CREATE TABLE test(id integer primary key, name text);"
sqlite3 tableWithOneRow.sqlite3 "INSERT INTO test values(1, 'first')"

touch tableForInsertionOfMultipleRows.sqlite3
sqlite3 tableForInsertionOfMultipleRows.sqlite3 "CREATE TABLE test(id integer primary key, name text);"

touch tableForInsertionOfEqualRows.sqlite3
sqlite3 tableForInsertionOfEqualRows.sqlite3 "CREATE TABLE test(id integer primary key, name text);"

