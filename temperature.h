void temperature()
{
    int f,t,k;
    float temp,max[]={100,212,373.15},min[]={0,32,273.15};
    char TEMP[][30]={"Celsius","Fahrenheit","Kelvin"}; 
    
    printf("\n Index   Temperature");
    for(k=1;k<4;k++)
        printf("\n| %d     | %s",k,TEMP[k-1]);
    printf("\n(Entering '0' terminates the program...)\n\n");  

    while(1)
    {
        printf("Enter the index of your 'FROM' temperature : ");
        scanf("%d",&f);
        if(f==0)
            goto exit;
        if(f<1 || f>3)
            continue;
        break;
    }
    while(1)
    {
        printf("Enter the index of your 'TO' temperature : ");
        scanf("%d",&t);
        if(t==0)
            goto exit;
        if(t<1 || t>3)
            continue;
        break;       
    }
    
    printf("Enter the temperature in %s : ",TEMP[f-1]);
    scanf("%f",&temp);
    temp=(temp-min[f-1])*(max[t-1]-min[t-1])/(max[f-1]-min[f-1])+min[t-1];
    printf("The temperature is : %.2f %c%c",temp,(char)248,TEMP[t-1][0]);
    
    exit:
        printf("\nThe Temperature Converter has terminated...\n");
}