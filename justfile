build day part:
    mkdir -p build
    cmake -DDAY_NUMBER={{day}} -DCOMPILE_SCRIPTS=OFF -S . -B build
    cmake --build build --target part{{part}}

build_parser day:
    mkdir -p build
    cmake -DCOMPILE_SCRIPTS=ON  -S . -B build 

clean:
    cmake --build build --target clean_all
    if [ -f input1.txt ]; then
    rm input1.txt
    fi

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

