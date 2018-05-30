#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 8
#define STATE_COUNT 18
#define SYMBOL_COUNT 17
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 0

enum {
  anon_sym_EQ = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  sym_identifier = 4,
  sym_date = 5,
  sym_string = 6,
  sym_loc_key = 7,
  sym_number = 8,
  sym_comment = 9,
  sym_program = 10,
  sym_statement = 11,
  sym_assignment_statement = 12,
  sym_expression = 13,
  sym_complex_expression = 14,
  sym_variable = 15,
  aux_sym_program_repeat1 = 16,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "END",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_identifier] = "identifier",
  [sym_date] = "date",
  [sym_string] = "string",
  [sym_loc_key] = "loc_key",
  [sym_number] = "number",
  [sym_comment] = "comment",
  [sym_program] = "program",
  [sym_statement] = "statement",
  [sym_assignment_statement] = "assignment_statement",
  [sym_expression] = "expression",
  [sym_complex_expression] = "complex_expression",
  [sym_variable] = "variable",
  [aux_sym_program_repeat1] = "program_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_loc_key] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_complex_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '\"')
        ADVANCE(2);
      if (lookahead == '#')
        ADVANCE(6);
      if (lookahead == '\'')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(10);
      if (lookahead == '0')
        ADVANCE(14);
      if (lookahead == '=')
        ADVANCE(29);
      if (lookahead == '[')
        ADVANCE(30);
      if (lookahead == '{')
        ADVANCE(33);
      if (lookahead == '}')
        ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(0);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(28);
      if ((lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '@') &&
          (lookahead < '[' || lookahead > '`') &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(35);
      END_STATE();
    case 1:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 2:
      if (lookahead == '\"')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\' &&
          lookahead != ']')
        ADVANCE(5);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 4:
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\"')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(5);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '\'')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\\' &&
          lookahead != ']')
        ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '\'')
        ADVANCE(3);
      if (lookahead == '\\')
        ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n')
        ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == '0')
        ADVANCE(11);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(13);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(12);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(13);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(15);
      if (lookahead == '0')
        ADVANCE(23);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(28);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0')
        ADVANCE(16);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(17);
      if (lookahead == '0')
        ADVANCE(21);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 17:
      if (lookahead == '0')
        ADVANCE(18);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(20);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '0')
        ADVANCE(19);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(20);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_date);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_date);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(20);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(22);
      END_STATE();
    case 23:
      if (lookahead == '.')
        ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == '0')
        ADVANCE(25);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(27);
      END_STATE();
    case 25:
      if (lookahead == '.')
        ADVANCE(17);
      if (lookahead == '0')
        ADVANCE(26);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == '.')
        ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(26);
      END_STATE();
    case 27:
      if (lookahead == '.')
        ADVANCE(17);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.')
        ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9'))
        ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 30:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '@') &&
          (lookahead < '[' || lookahead > '`') &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(31);
      END_STATE();
    case 31:
      if (lookahead == ']')
        ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '-') &&
          lookahead != '/' &&
          (lookahead < ':' || lookahead > '@') &&
          (lookahead < '[' || lookahead > '^') &&
          lookahead != '`' &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_loc_key);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '-') &&
          lookahead != '/' &&
          (lookahead < ';' || lookahead > '?') &&
          (lookahead < '[' || lookahead > '^') &&
          lookahead != '`' &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(35);
      END_STATE();
    case 36:
      if (lookahead == 0)
        ADVANCE(1);
      if (lookahead == '#')
        ADVANCE(6);
      if (lookahead == '-')
        ADVANCE(10);
      if (lookahead == '0')
        ADVANCE(11);
      if (lookahead == '=')
        ADVANCE(29);
      if (lookahead == '}')
        ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(36);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(13);
      if ((lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '@') &&
          (lookahead < '[' || lookahead > '`') &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(35);
      END_STATE();
    case 37:
      if (lookahead == '\"')
        ADVANCE(2);
      if (lookahead == '#')
        ADVANCE(6);
      if (lookahead == '\'')
        ADVANCE(7);
      if (lookahead == '-')
        ADVANCE(10);
      if (lookahead == '0')
        ADVANCE(14);
      if (lookahead == '[')
        ADVANCE(30);
      if (lookahead == '{')
        ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ')
        SKIP(37);
      if (('1' <= lookahead && lookahead <= '9'))
        ADVANCE(28);
      if (lookahead != 0 &&
          (lookahead < ' ' || lookahead > '#') &&
          (lookahead < '%' || lookahead > '@') &&
          (lookahead < '[' || lookahead > '`') &&
          (lookahead < '{' || lookahead > '~') &&
          lookahead != 160 &&
          lookahead != 8203 &&
          lookahead != 8288 &&
          lookahead != 65279)
        ADVANCE(35);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 36},
  [2] = {.lex_state = 36},
  [3] = {.lex_state = 36},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 36},
  [6] = {.lex_state = 36},
  [7] = {.lex_state = 36},
  [8] = {.lex_state = 37},
  [9] = {.lex_state = 37},
  [10] = {.lex_state = 36},
  [11] = {.lex_state = 36},
  [12] = {.lex_state = 36},
  [13] = {.lex_state = 36},
  [14] = {.lex_state = 36},
  [15] = {.lex_state = 36},
  [16] = {.lex_state = 36},
  [17] = {.lex_state = 36},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_date] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_loc_key] = ACTIONS(1),
    [sym_number] = ACTIONS(3),
    [sym_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(4),
    [sym_statement] = STATE(7),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [sym_number] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
  },
  [2] = {
    [ts_builtin_sym_end] = ACTIONS(13),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_RBRACE] = ACTIONS(13),
    [sym_identifier] = ACTIONS(13),
    [sym_number] = ACTIONS(13),
    [sym_comment] = ACTIONS(11),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_EQ] = ACTIONS(17),
    [anon_sym_RBRACE] = ACTIONS(15),
    [sym_identifier] = ACTIONS(15),
    [sym_number] = ACTIONS(15),
    [sym_comment] = ACTIONS(11),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym_comment] = ACTIONS(11),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_RBRACE] = ACTIONS(15),
    [sym_identifier] = ACTIONS(15),
    [sym_number] = ACTIONS(15),
    [sym_comment] = ACTIONS(11),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(15),
    [anon_sym_EQ] = ACTIONS(21),
    [anon_sym_RBRACE] = ACTIONS(15),
    [sym_identifier] = ACTIONS(15),
    [sym_number] = ACTIONS(15),
    [sym_comment] = ACTIONS(11),
  },
  [7] = {
    [sym_statement] = STATE(10),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(23),
    [sym_identifier] = ACTIONS(7),
    [sym_number] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
  },
  [8] = {
    [sym_expression] = STATE(13),
    [sym_complex_expression] = STATE(12),
    [sym_variable] = STATE(12),
    [anon_sym_LBRACE] = ACTIONS(25),
    [sym_identifier] = ACTIONS(7),
    [sym_date] = ACTIONS(27),
    [sym_loc_key] = ACTIONS(27),
    [sym_number] = ACTIONS(29),
    [sym_comment] = ACTIONS(11),
  },
  [9] = {
    [sym_expression] = STATE(13),
    [sym_complex_expression] = STATE(12),
    [sym_variable] = STATE(12),
    [anon_sym_LBRACE] = ACTIONS(25),
    [sym_identifier] = ACTIONS(7),
    [sym_date] = ACTIONS(27),
    [sym_string] = ACTIONS(31),
    [sym_loc_key] = ACTIONS(27),
    [sym_number] = ACTIONS(29),
    [sym_comment] = ACTIONS(11),
  },
  [10] = {
    [sym_statement] = STATE(10),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(33),
    [sym_identifier] = ACTIONS(35),
    [sym_number] = ACTIONS(38),
    [sym_comment] = ACTIONS(11),
  },
  [11] = {
    [sym_statement] = STATE(15),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(15),
    [anon_sym_RBRACE] = ACTIONS(41),
    [sym_identifier] = ACTIONS(7),
    [sym_number] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(43),
    [anon_sym_RBRACE] = ACTIONS(43),
    [sym_identifier] = ACTIONS(43),
    [sym_number] = ACTIONS(43),
    [sym_comment] = ACTIONS(11),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(45),
    [anon_sym_RBRACE] = ACTIONS(45),
    [sym_identifier] = ACTIONS(45),
    [sym_number] = ACTIONS(45),
    [sym_comment] = ACTIONS(11),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(47),
    [anon_sym_RBRACE] = ACTIONS(47),
    [sym_identifier] = ACTIONS(47),
    [sym_number] = ACTIONS(47),
    [sym_comment] = ACTIONS(11),
  },
  [15] = {
    [sym_statement] = STATE(17),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(17),
    [anon_sym_RBRACE] = ACTIONS(49),
    [sym_identifier] = ACTIONS(7),
    [sym_number] = ACTIONS(9),
    [sym_comment] = ACTIONS(11),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(51),
    [anon_sym_RBRACE] = ACTIONS(51),
    [sym_identifier] = ACTIONS(51),
    [sym_number] = ACTIONS(51),
    [sym_comment] = ACTIONS(11),
  },
  [17] = {
    [sym_statement] = STATE(17),
    [sym_assignment_statement] = STATE(5),
    [sym_variable] = STATE(6),
    [aux_sym_program_repeat1] = STATE(17),
    [anon_sym_RBRACE] = ACTIONS(33),
    [sym_identifier] = ACTIONS(35),
    [sym_number] = ACTIONS(38),
    [sym_comment] = ACTIONS(11),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = true}, RECOVER(),
  [3] = {.count = 1, .reusable = false}, RECOVER(),
  [5] = {.count = 1, .reusable = true}, REDUCE(sym_program, 0),
  [7] = {.count = 1, .reusable = true}, SHIFT(2),
  [9] = {.count = 1, .reusable = true}, SHIFT(3),
  [11] = {.count = 1, .reusable = true}, SHIFT_EXTRA(),
  [13] = {.count = 1, .reusable = true}, REDUCE(sym_variable, 1),
  [15] = {.count = 1, .reusable = true}, REDUCE(sym_statement, 1),
  [17] = {.count = 1, .reusable = true}, SHIFT(8),
  [19] = {.count = 1, .reusable = true}, ACCEPT_INPUT(),
  [21] = {.count = 1, .reusable = true}, SHIFT(9),
  [23] = {.count = 1, .reusable = true}, REDUCE(sym_program, 1),
  [25] = {.count = 1, .reusable = true}, SHIFT(11),
  [27] = {.count = 1, .reusable = true}, SHIFT(12),
  [29] = {.count = 1, .reusable = false}, SHIFT(12),
  [31] = {.count = 1, .reusable = true}, SHIFT(13),
  [33] = {.count = 1, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2),
  [35] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(2),
  [38] = {.count = 2, .reusable = true}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(3),
  [41] = {.count = 1, .reusable = true}, SHIFT(14),
  [43] = {.count = 1, .reusable = true}, REDUCE(sym_expression, 1),
  [45] = {.count = 1, .reusable = true}, REDUCE(sym_assignment_statement, 3),
  [47] = {.count = 1, .reusable = true}, REDUCE(sym_complex_expression, 2),
  [49] = {.count = 1, .reusable = true}, SHIFT(16),
  [51] = {.count = 1, .reusable = true}, REDUCE(sym_complex_expression, 3),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_ck2() {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
