 #include <stdio.h>
           #define EOF -1
           void push (int); /* push the argument on the stack */
           int pop  (void); /* pop the top of the stack */
           void flagError ();
           int main ()
          {         int c, m, n, r;
                     while ((c = getchar ()) != EOF)
                    { if  (isdigit (c) )
                               push (c);
                     else if ((c == '+') || (c == '*'))
                    {          m = pop ();
                                n = pop ();
                                r = (c == '+') ? n + m : n*m;
                                push (r);
                      }
                      else if (c != ' ')
                               flagError ();
             }
              printf("% c", pop ());
}