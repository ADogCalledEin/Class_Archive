# -*- coding utf-8 -*-
"""

Created by gsiadak @ 11:38 AM 4/4/16




To change to the training dataset for comparison the homework assignment,
change the specified values in the main function as commented


Hi Tyler!
"""
import time
from collections import Counter, defaultdict
from functools import partial
import math, random
import csv
import pprint


def entropy(class_probabilities):
    """given a list of class probabilities, compute the entropy"""
    return sum(-p * math.log(p, 2) for p in class_probabilities if p)


def class_probabilities(labels):
    total_count = len(labels)
    return [count / total_count
            for count in Counter(labels).values()]


def data_entropy(labeled_data):
    labels = [label for _, label in labeled_data]
    probabilities = class_probabilities(labels)
    return entropy(probabilities)


def partition_entropy(subsets):
    """find the entropy from this partition of data into subsets"""
    total_count = sum(len(subset) for subset in subsets)

    return sum( data_entropy(subset) * len(subset) / total_count
                for subset in subsets )


def partition_by(inputs, attribute):
    groups = defaultdict(list)
    for input in inputs:
        key = input[0][attribute]
        groups[key].append(input)
    return groups


def partition_entropy_by(inputs,attribute):
    """computes the entropy corresponding to the given partition"""
    partitions = partition_by(inputs, attribute)
    return partition_entropy(partitions.values())


def classify(tree, input):
    """classify the input using the given decision tree"""

    # if this is a leaf node, return its value
    if tree in [True, False]:
        return tree

    # otherwise find the correct subtree
    attribute, subtree_dict = tree

    subtree_key = input.get(attribute)  # None if input is missing attribute

    if subtree_key not in subtree_dict: # if no subtree for key,
        subtree_key = None              # we'll use the None subtree

    subtree = subtree_dict[subtree_key] # choose the appropriate subtree
    return classify(subtree, input)     # and use it to classify the input


def build_tree_id3(inputs, split_candidates=None):

    # if this is our first pass,
    # all keys of the first input are split candidates
    if split_candidates is None:
        split_candidates = inputs[0][0].keys()

    # count Trues and Falses in the inputs
    num_inputs = len(inputs)
    num_trues = len([label for item, label in inputs if label])
    num_falses = num_inputs - num_trues

    if num_trues == 0:                  # if only Falses are left
        return False                    # return a "False" leaf

    if num_falses == 0:                 # if only Trues are left
        return True                     # return a "True" leaf

    if not split_candidates:            # if no split candidates left
        return num_trues >= num_falses  # return the majority leaf

    # otherwise, split on the best attribute
    best_attribute = min(split_candidates, key=partial(partition_entropy_by, inputs))

    partitions = partition_by(inputs, best_attribute)
    new_candidates = [a for a in split_candidates
                      if a != best_attribute]

    # recursively build the subtrees
    subtrees = { attribute : build_tree_id3(subset, new_candidates)
                 for attribute, subset in partitions.items() }

    subtrees[None] = num_trues > num_falses # default case

    return best_attribute, subtrees



def main():

    input = csv.reader(open("house-votes-84.data.txt"))

    raw = []
    for row in input:
        raw.append(row)

    classes = []
    for row in raw:
        if row[0] == 'democrat':
            classes.append(True)
        else:
            classes.append(False)

    values = []
    for i in range(len(raw)):
        dict = ({'handicapped-infants':raw[i][1], 'water-project-cost-sharing':raw[i][2],
                 'adoption-of-the-budget-resolution':raw[i][3], 'physician-fee-freeze':raw[i][4],
                 'el-salvador-aid':raw[i][5], 'religious-groups-in-schools':raw[i][6],
                 'anti-satellite-test-ban':raw[i][7], 'aid-to-nicaraguan-contras':raw[i][8],
                 'mx-missile':raw[i][9], 'immigration':raw[i][10], 'synfuels-corporation-cutback':raw[i][11],
                 'education-spending':raw[i][12], 'superfund-right-to-sue':raw[i][13], 'crime':raw[i][14],
                 'duty-free-exports':raw[i][15],'export-administration-act-south-africa':raw[i][16]})

        values.append(dict)

    inputs = [(c,a) for c,a in zip(values,classes)]

    train_set = []
    for i in range(100):
        train_set.append(inputs[i])


    first_entropies = {}
    for key in ['handicapped-infants', 'water-project-cost-sharing', 'adoption-of-the-budget-resolution',
                'physician-fee-freeze', 'el-salvador-aid','religious-groups-in-schools', 'anti-satellite-test-ban',
                'aid-to-nicaraguan-contras', 'mx-missile', 'immigration', 'synfuels-corporation-cutback',
                'education-spending', 'superfund-right-to-sue', 'crime', 'duty-free-exports',
                'export-administration-act-south-africa']:
        first_entropies.update({key:partition_entropy_by(inputs, key)})  # CHANGE inputs TO train_set FOR TRAINING SET

    first_branch = min(first_entropies, key=first_entropies.get)
    tree = build_tree_id3(inputs) #ALSO CHANGE inputs TO train_set HERE

    guess = classify(tree, {'adoption-of-the-budget-resolution': 'y',
                            'export-administration-act-south-africa':'y',
                            'physician-fee-freeze':'n'})
    if guess == True:
        guess = "democrat"
    else:
        guess = "republican"

    pp = pprint.PrettyPrinter(indent=4)
    pp.pprint(tree)
    print("The congressperson is probably a %s" % guess)
    print("The first branch to split on is %s" % first_branch)




# COMPUTATIONAL TIMING #
start_time = time.time()
main()
end_time = time.time()
print("\nComputation Time: %g seconds" % round((end_time - start_time), 3))
