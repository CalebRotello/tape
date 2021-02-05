

//#include [stdio.tape]

fn main(argc: i32, argv: i8*[]): i32 
{
    let n = 6;   

    println(fib(n));

    return 0;
}

fn fib(n: i32): i32 
{
    if n <= 1 
        return 1;
    else
        return fib(n-1) + fib(n-2);
}
