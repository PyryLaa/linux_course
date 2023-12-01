#! /bin/bash
echo "Select food from list, press Ctrl-C to exit"
select food in Pizza Burger Sushi Pasta
do
    case $food in
	"Pizza" |"Pasta")
	    echo "You chose Italian food";;
	"Burger")
	    echo "You chose American food";;
	"Sushi")
	    echo "You chose Japanese food";;
	esac
done
