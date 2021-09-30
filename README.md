# push_swap
A Codam Coding College project made by Saladin Afoh

GOAL Write a library that contains ft_printf, a function
		that will mimic the real printf
		It will manage the following conversions: cspdiuxX%

CONVERSION:
		• %c print a single character. | cvrtchar
		• %s print a string of characters. | cvrtstr
		• %p The void * pointer argument is printed in hexadecimal. | cvrtp
		• %d print a decimal (base 10) number. | cvrtd
		• %i print an integer in base 10. | cvrti
		• %u print an unsigned decimal (base 10) number. | cvrtu
		• %x print a number in hexadecimal (base 16). | cvrtx
		• %% print a percent sign.

# Usage
1. make;
	to compile the project
2. make re:
	to recompile the project
3. make re ft_printf_tester
	to run the simple unit test
4. make re ft_printf_test
	to run the more complicated unit test
5. make fclean; make fclean DEBUG=1:
	to clean all of the libraries, including libft.
6. make re main; ./printf_gdb:
	to prepare a debuggable executable

# Usefull README tips and tricks;
1. A README file is a guide that gives users a detailed description
	of a project that you have pushed to your repository.
2. A good README helps your projects stand out from a bunch of other 
	projects. It should be as good as the project itself.
3. It is the first file a person will see when they encounter your project,
	so it should be fairly brief but detailed.
4. It will help you focus on what your project needs to deliver and how.

A README needs to answer the following what, why, and how:

What was your motivation?
Why did you build this project?
What problem does it solve?
What did you learn?
What makes your project stand out? 
If your project has a lot of features, 
consider adding a "Features" section and listing them here.

# Writing a Good README file
Include Your Project's Title
Write a Description
	What your application does,
	Why you used the technologies you used,
	Some of the challenges you faced and features you hope to implement in the future.
Add a Table of Contents (Optional)
How to Install Your Project
How to Use Your Project
Include Credits
List the License
Badges
How to Contribute to the Project
Include Tests
