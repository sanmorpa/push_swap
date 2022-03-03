<h1>push_swap</h1>
<h2>Project description</h2>
<div>
<!--  <a href="https://github.com/JaeSeoKim/badge42">
    <img align="center" src="https://badge42.herokuapp.com/api/project/samoreno/ft_printf"/>
  </a> -->
  <p>This is the fourth project at 42 Madrid. The aim is to learn how to write a sorting algorithm, rigor, use of C and use of basic algorithms. The goal is to create a program that sorts a list of n numbers. The sepcifications are as here follows:
  <ul>
    <li>The game is composed of 2 stacks named a and b</li>
    <li>At the start the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated and b is empty</li>
    <li>The goal is to sort in ascending order numbers into stack a</li>
    <li>To do this there is a limited number of allowed operations</li>
    <ul>
      <li>sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements)</li>
      <li>sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements)</li>
      <li>ss : sa and sb at the same time</li>
      <li>pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty</li>
      <li>pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty</li>
      <li>ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one</li>
      <li>rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one</li>
      <li>rr : ra and rb at the same time</li>
      <li>rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one</li>
      <li>rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one</li>
      <li>rr : rra and rrb at the same time</li>
    </ul>
  </ul>
  </p>
  <p>
  The program named push_swap receives as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack. The program display a list of instructions to sort the stack a. If no parameters are specified, the program displays nothing. In case of error the console displays <b>Error<b/>. Errors include for example: some arguments aren’t integers, some arguments are bigger or samller than an integer, and/or there are duplicates.
  </p>
</div>
<h2>Usage</h2>
<div>
    <p>
        With the Makefile you can compile directly. The rules that it allows are:
        <ul>
         <li>Make: it compiles directly</li>
         <li>Make re: if the project is already compiled, it does it again</li>
         <li>Make clean. Deletes all .o files but the executable remains</li>
         <li>make fclean: deletes all .o files and the executable</li>
    </ul>
    </p>
      Launch the program as follows:<br/>
  <b>./push_swap &lt;list of n non-repeated numbers&gt;</b><br/>
        or
        <b>./push_swap &lt;"list of n non-repeated numbers"&gt;</b>
    </p>
</div>
