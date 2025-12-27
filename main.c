// GOAL: build a Inference Engine (FORWARD CHAINING, BACKWARD CHAINING)

/* STEPS:
    --> Knowldge Base = Facts + Rules
    - Facts: From User ['A', 'B', 'C', 'D']
    - Rules: [{'R1': ['A', 'B', 'C']}, {'R2': ['S', 'D', 'A']}, ...]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


int main() {

    // Get Facts
    Facts facts;
    returnFacts(&facts);
    
    // Get The Rules
    RuleBase ruleBase1;
    getAllRuleBase(&ruleBase1);
    
    
    // Init The KB = Rule + Facts
    initTheKB(&facts, &ruleBase1);
    
    // Display Rules and Facts
    displayRuleAndFacts(ruleBase1, facts);
    
    // Make Inference With Forward Chaining
    getGoalWithForwardChaining(ruleBase1, facts);
    
    return 0;
}








