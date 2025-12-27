#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


void returnFacts(Facts *facts) {
    printf("Enter The Size of Facts: ");
    scanf("%d", &facts->size);

    char fact;
    int count = 0;
    facts->factsSymbols = (char *) calloc(facts->size, sizeof(char));

    printf("\nEnter Facts (If End Of Facts Enter !): \n");
    for (int i = 0; i < facts->size; i++) {
        scanf(" %c", &fact);
        if (fact == '!') break;
        else {
            facts->factsSymbols[i] = fact; count++;
        }
    }
    facts->size = count;
    printf("\n");
}


void returnRule(Rule *rule) {
    printf("Enter Rule name: ");
    scanf("%s", rule->ruleName);
    printf("Enter Rule Conclusion: ");
    scanf(" %c", &rule->ruleConclusion);
    Facts *facts;
    returnFacts(facts);
    rule->ruleFacts = facts;
}


void getAllRuleBase(RuleBase *ruleBase1) {
    printf("Enter Number of Rules: ");
    scanf(" %d", &ruleBase1->ruleBaseNumber);
    
    ruleBase1->rules = (Rule *) calloc(ruleBase1->ruleBaseNumber, sizeof(Rule));
    for (int i = 0; i < ruleBase1->ruleBaseNumber; i++) {
       returnRule(&ruleBase1->rules[i]);
    }
}


void displayRuleAndFacts(RuleBase ruleBase1, Facts facts) {
    // Display The Facts
    printf("\n---------------------------------------");
    printf("\n>>>> Facts: [");
    for (int i = 0; i < facts.size; i++) {
        printf("%c, ", facts.factsSymbols[i]);
    }
    printf("]\n");
    
    // Display The Rules
    printf(">>>> RuleBase: {\n");
    for (int i = 0; i < ruleBase1.ruleBaseNumber; i++) {
        Rule rule = ruleBase1.rules[i];
        printf("%s: ", rule.ruleName);
        printf("%s: ", rule.ruleFacts->factsSymbols);
        printf("→ %c \n", rule.ruleConclusion);
    }
    printf("}\n");
    printf("---------------------------------------\n");
}


char returnConclusion(Facts *factsOfRule, Facts facts, NAryTree *nAryTree) {
    printf(">>>>> ruleFact: %s\n", factsOfRule->factsSymbols);
    printf(">>>>> fact: %s\n", facts.factsSymbols);

    for (int i = 0; i < factsOfRule->size; i++) {
        
    }
}

void getGoalWithForwardChaining(RuleBase ruleBase1, Facts facts) {
    // Init The Root in TREE
    NAryTree nAryTree;
    nAryTree.facts = facts;
    nAryTree.numFacts = facts.size;

    // Start Getting Other Facts Based on Facts
    for (int i = 0; i < ruleBase1.ruleBaseNumber; i++) {
        Rule rule = ruleBase1.rules[i];
        for (int j = 0; j < facts.size; i++) {
            // Verify all rules facts exit in Facts
            returnConclusion(rule.ruleFacts, facts, &nAryTree); /// ruleFacts is pointer
        }
    }
}


void initTheKB(Facts *facts, RuleBase *ruleBase1) {
    
}





















