void currency()
{
    float amt,conv_const[20];
    char curr_code[20][4],curr_name[20][30],line[100];
    int f,t,i;
    FILE *fp;
    fp=fopen("curr1.csv","r");
    
    for(i=0;i<20;i++)
    {
        fgets(line,100,fp);
        conv_const[i]=atof(strtok(line,","));
        strcpy(curr_code[i],strtok(NULL,","));
        strcpy(curr_name[i],strtok(NULL,","));
    }
    printf("\n Index   Code     Currency\n");
    for(i=1;i<10;i++)    
        printf("| %d     | %s    | %s",i,curr_code[i-1],curr_name[i-1]);    
    for(i=10;i<21;i++)    
        printf("| %d    | %s    | %s",i,curr_code[i-1],curr_name[i-1]);    
    printf("\n(Entering '0' terminates the program...)\n\n");  

    while(1)
    {
        printf("Enter the index of your 'FROM' currency : ");
        scanf("%d",&f);
        if(f==0 )
            goto exit;
        if (f<1 || f>20)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter the index of your 'TO' currency : ");
        scanf("%d",&t);
        if(t==0)
            goto exit;            
        if (t<1 || t>20)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter your amount in %s : ",curr_code[f-1]);
        scanf("%f",&amt);
        if(amt<0)
            continue;
        break;
    }

    amt=amt*conv_const[f-1];
    amt=amt/conv_const[t-1];    

    printf("Your amount in %s is : %.2f",curr_code[t-1],amt);    
    exit:
        printf("\nThe Currency Converter has terminated...\n");    
}