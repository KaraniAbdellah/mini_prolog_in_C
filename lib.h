#ifndef MYHEADER_H
#define MYHEADER_H



// EXAMPLE: {4, ['A', 'B', 'C', 'D']}
typedef struct Facts {
    int size;
    char *factsSymbols;
} Facts;


// EXAMPLE:  {ruleName: "R1", ruleFacts: [size: 4, factsSymbols: ['A', 'B', 'D', ...]], ruleConclusion: 'F'}
typedef struct Rule {
    char ruleName[3];
    Facts *ruleFacts;
    char ruleConclusion;
} Rule;


// EXAMPLE: [{ruleBaseNumber: 2, rules: [{ruleName: "R1", ruleFacts: [{size: 3, factsSymbols: ['A', 'B', 'C'], {}, ...}]}]]
typedef struct RuleBase {
    int ruleBaseNumber;
    Rule *rules;
} RuleBase;


typedef struct NAryTree {
    Facts facts; // Normall this is FactBase
    int numFacts;
    struct NAryTree **NAryTreeFacts;
} NAryTree;


void sayHello();
void returnFacts(Facts *facts);
void returnRule(Rule *rule);
void getAllRuleBase(RuleBase *ruleBase1);
void displayRuleAndFacts(RuleBase ruleBase1, Facts facts);
char returnConclusion(char *ruleFact, char *fact);
void getButWithForwardChaining(RuleBase ruleBase1, Facts facts);
void initTheKB(Facts *facts, RuleBase *ruleBase1);







#endif
