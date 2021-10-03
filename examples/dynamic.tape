

fn main(argc: i32, argv: i8*[]): i32 {
   
    if (argc != 2) 
        return 0;

    var BUFF: char[255];
    var in: i32;
    var i: i32 = 0;
    var fp: FILE* = fopen(argv[1],"r");    // read in file

    // get n
    fscanf(fp,"%d",&in);
    let n = in;
    // get k
    fscanf(fp,"%d",&in);
    i32 k = in;

    // create block
    i32[n] BLOCK; 
    while(fscanf(fp,"%d",&in)!=EOF){
        BLOCK[i] = in; 
        i++;
    }
    fclose(fp);


    clock_t begin = clock();
//    i32 result = recursive_partition(BLOCK,0,n,k);
    clock_t end = clock();
    f64 time_spent = (f64)(end-begin) / CLOCKS_PER_SEC;
//    pri32f("%d \n", time_spent);
    
    i32 result = table_partition(BLOCK, n, k);
    pri32f("%d \n",result);
}

// use a table to partition
i32 table_partition(i32 *B, i32 n, i32 k) {
    i32[n][k] P;
    i32[n][k] T;
    i32[n] S;
    i32 i,j,x,fair;

    S[0] = B[0];
    for(i=0; i<n; i++) 
        S[i] = S[i-1] + B[i];
    for(i=0; i<n; i++) 
        P[i][0] = S[i];
    for(j=1; j<k; j++) 
        P[0][j] = 0;
    
    for(i=1; i<n; i++){
        for(j=1; j<k; j++) {
            P[i][j] = 0;
            for(x=0; x<i; x++) {
                fair = S[i] - S[x];
                if (fair > P[x][j-1]) 
                    fair = P[x][j-1];
                if (fair > P[i][j]) {
                    P[i][j] = fair;
                    T[i][j] = x+1;
                }
            }
        }
    }
    reconstruct_table(B,@T,n,k,k);
    pri32f("\n");
    return P[n-1][k-1];
}


// pri32 table
i32 reconstruct_table(i32 *B, i32 *T, i32 n, i32 k, i32 s_k) {
    if (k==1) {
        pri32_block(B,0,n);
        pri32f("D ");
        return 0;
    }
    else {
        reconstruct_table(B, T, T[(n-1)*s_k+k-1], k-1,s_k);
        pri32_block(B,T[(n-1)*s_k+k-1],n);
        if (k == s_k) return 0; // dont pri32 last d 
        pri32f("D ");
    }
}

// pri32
i32 pri32_block(i32 *BLOCK, i32 s, i32 e) {
    for (i32 i = s; i < e; i++) pri32f("%d ", BLOCK[i]);
}

i32 recursive_partition(i32 *BLOCK, i32 i, i32 n, i32 k) {
    // base case k=1
    if (k==1) return sum(BLOCK,i,n);
    // base case blocksize = 1
    if (i-n==1) return 0;//BLOCK[i];
    i32 min = 1215752192;
    i32 max, d;
    // loop over block
    for(i32 j = i; j<n; j++) {
        // get recursive with [0:j],k-1
        i32 rightSum = recursive_partition(BLOCK,i,j,k-1);
        // sum remainder [j+1:n]
        i32 leftSum = sum(BLOCK,j+1,n); 
        if (leftSum>rightSum) max = leftSum;
        else max = rightSum;
        if (max < min) {
            d = j;
            min = max;
        }
    }
    return min;
}

///*
//i32 reconstruct_partition(i32 *BLOCK, i32 n, i32 k) {
//    if (k==1) pri32_books(BLOCK,1,n);
//    else {
//        reconstruct_partition(BLOCK,n,k-1);
////        pri32_books(s,
//    }
//    return 0;
//}
//*/

/*
//i32 pri32_books(i32 *BLOCK, i32 s, i32 e) {
//    i32 i;
//    for (i=s; i<=e; i++) pri32f(" %d ",BLOCK[i]);
//    pri32f("\n");
//}
*/

i32 sum(i32 *SUB, i32 i, i32 n) {
    i32 s = 0;
    for (i; i<n; i++) {
        s = s+SUB[i];
    }
    return s;
}




