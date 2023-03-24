void time()
{
    char line[100],code[30][50],tm[5],week[][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Monday"};
    int diff[30],f,t,i,hr,min,day;
    FILE *fp=fopen("time.csv","r");
    
    for(i=0;i<30;i++)
    {
        fgets(line,100,fp);
        diff[i]=atof(strtok(line,","));
        strcpy(code[i],strtok(NULL,","));
    }

    printf("\n Index   Name\n");
    for(i=1;i<10;i++)    
        printf("| %d     | %s",i,code[i-1]);    
    for(i=10;i<31;i++)    
        printf("| %d    | %s",i,code[i-1]);
    printf("\n(Entering '0' terminates the converter...)\n\n"); 

    while(1)
    {
        printf("Enter the index of your 'FROM' timezone : ");
        scanf("%d",&f);
        if(f==0 )
            goto exit;
        if (f<1 || f>30)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter the index of your 'TO' timezone : ");
        scanf("%d",&t);
        if(t==0)
            goto exit;            
        if (t<1 || t>30)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter time in 24hr format (hr:min) : ");
        scanf("%d:%d",&hr,&min);
        if(hr<0 || hr>23 || min<0 || min>59)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter day (1-> Monday , 7-> Sunday) : ");
        scanf("%d",&day);
        if(day<1 || day>7)
            continue;
        break;
    } 

    min=hr*60+min;
    min=min-diff[f-1];
    min=min+diff[t-1];

    if(min<0)
    {
        day--;
        min=min+1440;
    }
    if(min>1440)
    {
        day++;
        min=min-1440;
    }
    if((min/60)<10)
       printf("\nTimezone : %sTime : %d%d:%d\nDay : %s",code[t-1],0,min/60,min%60,week[day]);
    else if((min%60)<10)
       printf("\nTimezone : %sTime : %d:%d%d\nDay : %s",code[t-1],min/60,0,min%60,week[day]);
    else if((min/60)<10 && (min%60)<10)
       printf("\nTimezone : %sTime : %d%d:%d%d\nDay : %s",code[t-1],0,min/60,0,min%60,week[day]);
    else
    printf("\nTimezone : %sTime : %d:%d\nDay : %s",code[t-1],min/60,min%60,week[day]);   
    exit:
        printf("\nThe Time Converter has terminated...\n");
}