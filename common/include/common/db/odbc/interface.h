/**
 * PLAIN SERVER Engine ( https://github.com/viticm/plainserver )
 * $Id interface.h
 * @link https://github.com/viticm/plianserver for the canonical source repository
 * @copyright Copyright (c) 2014- viticm( viticm.ti@gmail.com )
 * @license
 * @user viticm<viticm.it@gmail.com>
 * @date 2014/07/11 15:45
 * @uses the odbc interface class(some op functions)
 *       version 2.0
 */
#ifndef PS_COMMON_DB_ODBC_INTERFACE_H_
#define PS_COMMON_DB_ODBC_INTERFACE_H_

#include "common/db/odbc/config.h"
#include "common/sys/memory/static_allocator.h"
#include "common/util/compressor/mini.h"

//include from odbc
#ifndef VOID
#define VOID void //for unixODBC
#endif

#include "sql.h"
#include "sqlext.h"

namespace ps_common_db {

namespace odbc {

class Interface {
 public:
   enum
   {
     COLUMN_MAX = 100,
     BLOB_BATCH = 10000,
     QUERY_OK = 0,
     QUERY_NULL = -100,
     QUERY_EOF = -101,
     QUERY_NO_COLUMN = -102,
     QUERY_ERROR = -103,
   };
   bool connected_;
   SQLHENV sql_henv_;
   SQLHDBC sql_hdbc_;
   SQLRETURN result_;
   char connection_name_[DB_CONNECTION_NAME_LENGTH];
   char user_[DB_USER_NAME_LENGTH];
   char password_[DB_PASSWORD_LENGTH];

   SQLLEN affect_count_;
   SQLHSTMT sql_hstmt_;
   
   /* column about { */
   SQLSMALLINT column_count_;
   char **column_names_;
   SQLSMALLINT *column_type_;
   char **column_typenames_;
   SQLULEN *column_size_;
   SQLSMALLINT *column_precision_;
   SQLSMALLINT *column_nullable_;
   char **column_values_;
   SQLINTEGER *column_valuelengths_;
   ps_common_sys::memory::StaticAllocator column_info_allocator_;
   char column_info_buffer[COLUMN_INFO_BUFFER_MAX];
   ps_common_sys::memory::StaticAllocator column_value_allocator_;
   char column_value_buffer[COLUMN_VALUE_BUFFER_MAX];
   /* column about } */

   ps_common_util::compressor::Mini compressor_;

   db_query_t query_;
   SQLINTEGER error_code_;
   SQLCHAR error_message_[ERROR_MESSAGE_LENGTH_MAX];

 public:
   Interface();
   ~Interface();
   bool connect(const char *connection_name, 
                const char *user = NULL, 
                const char *password = NULL);
   bool connect();
   bool close();
   bool failed(int32_t code);
   bool collect_resultinfo();
   int32_t get_error_code();
   const char *get_error_message();
   bool is_connected();
   int32_t get_affect_row_count();
   SQLSMALLINT get_typemapping(SQLSMALLINT typecode);
   bool is_prepare();
   void clear();
   void clear_no_commit();
   void clear_column_info();
   void clear_column_data();
   int32_t get_columncount() const;
   bool fetch(int32_t orientation = SQL_FETCH_NEXT, int32_t offset = 0);
   db_query_t& get_query();
   bool execute();
   bool execute(const char *sql_str);

 public:
   float get_float(int32_t column_index, int32_t& error_code);
   int64_t get_int64(int32_t column_index, int32_t& error_code);
   uint64_t get_uint64(int32_t column_index, int32_t& error_code);
   int32_t get_int32(int32_t column_index, int32_t& error_code);
   uint32_t get_uint32(int32_t column_index, int32_t& error_code);
   int16_t get_int16(int32_t column_index, int32_t& error_code);
   uint16_t get_uint16(int32_t column_index, int32_t& error_code);
   int8_t get_int8(int32_t column_index, int32_t& error_code);
   uint8_t get_uint8(int32_t column_index, int32_t& error_code);
   int32_t get_string(int32_t column, 
                      char *buffer, 
                      int32_t buffer_length, 
                      int32_t& error_code);
   int32_t get_field(int32_t column_index, 
                     char *buffer, 
                     int32_t buffer_length, 
                     int32_t& error_code);
   int32_t get_binary(int32_t column_index, 
                      char *buffer, 
                      int32_t buffer_length, 
                      int32_t& error_code);
   int32_t get_binary_withdecompress(int32_t column_index, 
                                     char *buffer, 
                                     int32_t buffer_length, 
                                     int32_t& error_code);
   const char *get_data(int32_t column, const char *_default = NULL);
   const char *get_data(const char *columnname, const char *_default = NULL);
   int32_t get_datalength(int32_t column) const;
   int32_t get_column(const char *columnname) const;
   int16_t get_size(int32_t column) const;
   int16_t get_precision(int32_t column) const;
   int16_t get_nullable(int32_t column) const;
   const char *get_name(int32_t column);
   int16_t get_type(int32_t column) const;
   const char *get_typename(int16_t column);
   ps_common_util::compressor::Mini *getcompressor();
   //分析
   void diag_state();
   void save_error_log(const char *log);
   void save_warning_log(const char *log);
   void clear_env();
   void dump(int32_t column);
};

}; //namespace odbc

}; //namespace ps_common_db

#endif //PS_COMMON_DB_ODBC_INTERFACE_H_
