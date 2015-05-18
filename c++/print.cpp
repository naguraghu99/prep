void fun(int i)

{

    if(i>1)

    {

        fun(i/2);

        fun(i/2);

    }

    printf("#"); 

}



int main()

{

    fun(4);
}
