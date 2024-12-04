build day part:
    mkdir -p build
    cmake -DDAY_NUMBER={{day}} -DCOMPILE_SCRIPTS=OFF -S . -B build
    cmake --build build --target part{{part}}
    cmake --build build --target part{{part}}_test

build_parser day:
    mkdir -p build
    cmake -DCOMPILE_SCRIPTS=ON  -S . -B build 

clean:
    ./scripts/run2.sh
    cmake --build build --target clean_all
  

create day:
    ./scripts/run.sh {{day}}
    just get-input {{day}}

get-input day:
    just build_parser {{day}} 
    cmake --build build --target AOC_parser
    ./build/scripts/AOC_parser {{day}}

run day part:
    just build {{day}} {{part}}
    ./build/day-{{day}}/part{{part}}/part{{part}}
    


