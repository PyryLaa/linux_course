#! /bin/bash
GLOBIGNORE="*" #To allow the use of asterisk as multiplication operator rather than filename expansion

if [ $# -eq 0 ];then
    echo "Give the amount of operations as cli argument"
    exit 1
fi
op_amount=$1

echo "This is a simple calculator program"
echo "it accepts integers as numbers"
echo "and the accepted operations are:"
echo "+ - / * ^"

add(){
    echo "$(($1+$2))" #Use echo instead of return to generate output
}

subs(){
    echo "$(($1-$2))"
}

mult(){
    echo "$(($1*$2))"
}

div(){
    if [ "$2" -eq 0 ];then
	echo "Division by zero not possible"
    else
	echo "$(($1/$2))"
    fi
}

exp(){
    echo "$(($1**$2))"
}


main_calc(){
    local result
    if [ $3 == '+' ];then
	result=$(add $1 $2) #Command substitution to capture output of add function
    elif [ $3 == '-' ];then
	result=$(subs $1 $2)	
    elif [ $3 == '*' ];then
	result=$(mult $1 $2)
    elif [ $3 == '/' ];then
	result=$(div $1 $2)
    elif [ $3 == '^' ];then
	result=$(exp $1 $2)
    fi

    echo "${result}"
}

    
until [ $op_amount -eq 0 ]
do
    echo "Give first number: "
    read num1
    echo "Give second number: "
    read num2
    echo "Give operation: "
    read op
    result=$(main_calc ${num1} ${num2} ${op})
    echo "The calculation was ${num1} ${op} ${num2}"
    echo "And the result is: ${result}"
    ((op_amount--))
done

