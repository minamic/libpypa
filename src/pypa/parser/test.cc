// Copyright 2014 Vinzenz Feenstra
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <pypa/parser/parser.hh>
#include <stdio.h>

namespace pypa {
    void dump(AstPtr);
}

int main(int argc, char const ** argv) {
    if(argc != 2) {
        return 1;
    }
    pypa::AstModulePtr ast;
    pypa::Parser parser;
    pypa::ParserOptions options;
    options.python3allowed = true;
    pypa::Lexer lexer(argv[1]);
    if(parser.parse(lexer, ast, options)) {
        printf("Parsing successfull\n");
        dump(ast);
    }
    else {
        printf("Parsing failed\n");
        return 1;
    }
    return 0;
}
