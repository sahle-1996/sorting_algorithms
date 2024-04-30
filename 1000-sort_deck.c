#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * @deck: doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;

	if (!deck || !*deck)
		return;

	len = list_len_deck(*deck);

	if (len < 2)
		return;

	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
			swap_cards(curr->prev, curr);
		else
			curr = curr->next;
	}
}

/**
 * card_value - returns the value of a card
 * @node: card in a deck
 *
 * Return: value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int value = 0;

	for (int i = 0; i < 13; i++)
	{
		if (!_strcmp(node->card->value, val[i]))
			value = i + 1;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!_strcmp(node->card->kind, kinds[i]))
			value += (i * 13);
	}

	return (value);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - function returns length of list
 * @list: head of list
 *
 * Return: length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * swap_cards - swaps the positions of two cards in a deck
 * @card1: first card
 * @card2: second card
 */
void swap_cards(deck_node_t *card1, deck_node_t *card2)
{
	deck_node_t *prev1 = card1->prev;
	deck_node_t *next2 = card2->next;

	if (prev1)
		prev1->next = card2;
	card2->prev = prev1;
	card2->next = card1;
	card1->prev = card2;
	card1->next = next2;
	if (next2)
		next2->prev = card1;
}
