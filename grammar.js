module.exports = grammar({
  name: "ck2",

  extras: $ => [$.comment, /\s/],

  rules: {
    program: $ => repeat(
      $.statement
    ),

    statement: $ => choice(
      $.assignment_statement,
      $.variable,
      $.number
    ),

    assignment_statement: $ => choice(
      seq($.variable, "=", $.expression),
      seq($.variable, "=", $.string),
      seq($.number, "=", $.expression),
    ),

    expression_statement: $ => seq(
      $.expression
    ),

    expression: $ => choice(
      $.variable,
      $.number,
      $.loc_key,
      $.date,
      $.complex_expression
    ),

    complex_expression: $ => seq(
      "{", repeat($.statement), "}"
    ),

    identifier: $ => {
      const alpha = /[^\s0-9:;`"'@#.,|_^&<=>+\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u00A0]/
      const alpha_numeric = /[^\s;`"'#,|^&<=>+\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u00A0]/

      return token(seq(alpha, repeat(alpha_numeric)))
    },

    variable: $ => seq(
      $.identifier
    ),

    date: $ => {
      const decimal_digits = /\d+/

      const decimal_integer_literal = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(decimal_digits))
      )

      const date_literal = seq(
        decimal_integer_literal,repeat(decimal_digits),'.',
        decimal_integer_literal,repeat(decimal_digits),'.',
        decimal_integer_literal,repeat(decimal_digits)
      )

      return token(
        date_literal
      )
    },

    string: $ => token(choice(
        seq('"', optional(seq(choice(/[^"\\\n\]]/, /\\./), repeat(choice(/[^"\\\n]/, /\\./)))), '"'),
        seq("'", optional(seq(choice(/[^'\\\n\]]/, /\\./), repeat(choice(/[^'\\\n]/, /\\./)))), "'")
      )),

    loc_key: $ => {
      const alpha = /[^\s0-9:;`"'@#.,|_^&<=>+\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u00A0]/
      const alpha_numeric = /[^\s:;`"'@#,|^&<=>+\-*/\\%?!~()\[\]{}\uFEFF\u2060\u200B\u00A0]/

      return token(
        seq(("["), seq(alpha, repeat(alpha_numeric)), "]")
      )
    },

    number: $ => {
      const decimal_digits = /\d+/

      const decimal_integer_literal = choice(
        '0',
        seq(optional('0'), /[1-9]/, optional(decimal_digits))
      )

      const decimal_literal = choice(
        seq(optional('-'), decimal_integer_literal, '.', optional(decimal_digits)),
        seq(optional('-'), decimal_integer_literal)
      )

      return token(
        decimal_literal
      )
    },

    comment: $ => /#.*/
  }
});
