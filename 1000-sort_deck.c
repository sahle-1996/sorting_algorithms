#include "deck.h"
#include <stddef.h>

/**
 * _strcmp - compare two strings
 * @str1: string
 * @str2: string
 * Return: 0 if strings are different, 1 if they are equal
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;

	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}

	return (str1[i] == '\0' && str2[i] == '\0');
}

/**
 * get_card_position - return the position based on card value and kind
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(deck_node_t *node)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int value = 0;

	for (int i = 0; i < 13; i++)
	{
		if (_strcmp(node->card->value, values[i]))
		{
			value = i + 1;
			break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (_strcmp(node->card->kind, kinds[i]))
		{
			value += i * 13;
			break;
		}
	}

	return (value);
}

/**
 * swap_card - swap a card for its previous one
 * @card: card to swap
 * @deck: card deck
 * Return: return a pointer to the entered card
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev;
	deck_node_t *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;

	return (current);
}

/**
 * insertion_sort_deck - sorts a doubly linked deck in ascending order
 * using the Insertion sort algorithm
 * @deck: doubly linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	deck_node_t *node = (*deck)->next;

	while (node)
	{
		int value_prev, value_current;
		deck_node_t *prev = node->prev;

		if (prev)
		{
			value_prev = get_card_position(prev);
			value_current = get_card_position(node);
		}

		while (prev && value_prev > value_current)
		{
			value_prev = get_card_position(prev);
			value_current = get_card_position(node);
			node = swap_card(node, deck);
			prev = node->prev;
		}

		node = node->next;
	}
}

/**
 * sort_deck - sorts a deck using insertion sort algorithm
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
