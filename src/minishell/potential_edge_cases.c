
// in the case above the single quotes disables EOF
// VAR="Hello"
// cat <<'EOF'
// $VAR, World!
// EOF

// multiple redirections with files
// CHECK BASH

// f1r2s5% echo 5 | echo 2 | echo love | cat > alpha.txt | cat << EOF
// pipe pipe pipe pipe heredoc> la
// pipe pipe pipe pipe heredoc> la
// pipe pipe pipe pipe heredoc> la
// pipe pipe pipe pipe heredoc> EOF
// love
// la
// la
// la

//echo 1 | cat < alpha.txt < beta.txt > example.txt
//echo 1 | cat > alpha.txt < beta.txt > example.txt   *** harder to understand
//echo diane | cat < alpha.txt < beta.txt > example.txt

//** echo hello < file hello  
//check permissions of file - if not allowed, it will give an error
//this will also give error echo hello < < file hello 

// cat | cat | ls  -- on the eval sheet

// echo -n that's what i said