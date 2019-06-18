#!/usr/bin/env bash
touch oneEmptyTableDb.sqlite3
sqlite3 oneEmptyTableDb.sqlite3 "CREATE TABLE test(id integer primary key, name text);"