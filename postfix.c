# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# define MAX 100
# define ROGUE -999999

/*       Structures   */
typedef struct {
		char stk[MAX+1];
		}NodeData; //NodeData Declaration
		
typedef struct treenode {
		NodeData data;
		struct treenode *left, *right;
		}TreeNode, *TreeNodePtr; //Tree Node Declaration
		
typedef struct {
		TreeNodePtr root;
		}BinaryTree; //Binary Tree Declaration

typedef struct {
        int top;
        double val[MAX];
        }StackNode, *Stack; //Stack Declaration

/*      Stack Manipulating Functions */        
Stack createStack (){
      Stack s=(Stack)malloc(sizeof(StackNode));
      s->top=-1;
      return s;
      } //Creates an empty stack
      
void push (Stack s, double d){
     s->top=s->top+1;
     s->val[s->top]=d;
     } //Adds an item at the head of the stack
     
double pop (Stack s){
       double pitem;
       if (s->top >= 0){
                  pitem=s->val[s->top];
                  s->top=s->top-1;
                  return pitem;
       } //Removes an item from the top of the stack
}

double peek (Stack s){
       //int pk;
       if (s->top >= 0) return s->val[s->top];
       else return ROGUE;
       } //Allows viewing of the topmost item in the stack
       
      
/*    Binary Tree Manipulating Functions */
TreeNodePtr buildBtree(FILE * in){
	char item[MAX];
	
	fscanf (in, "%s", item);
	if (strcmp(item, "@")==0) return NULL;
    TreeNodePtr bst = (TreeNodePtr) malloc (sizeof(TreeNode));
	strcpy (bst->data.stk, item);
	bst->left=buildBtree(in);
	bst->right=buildBtree(in);
	return bst;
    }//Builds Binary Tree
	
    

void visit (Stack s, TreeNodePtr bst){
     //visits each node and uses arithmetic and stack manipulating 
     //functions to push, pop and calculate the results.
     void push (Stack, double);
     double add(double, double), sub(double, double), mult(double, double), divd(double, double), peek(Stack);
     double item, sol, num1, num2;
     int i=0, boolid;
     //Ends if no more characters are in the string
     while (bst->data.stk[i]!='\0'){
           
           if (isdigit(bst->data.stk[i])){
              i++;
              boolid=1; //Boolean manipulation, 1 true, 0 false
                         }
           else {
               boolid=0; 
               i++;
           }                      
           }
           
           if (boolid==1){// character is an operand
              item=atoi(bst->data.stk);
              push (s, item);
           }                          
           
           if (boolid==0){// character is an operator
             //Applies the operator function to the values in the stack 
              if (strcmp(bst->data.stk, "+")==0){
                 num2=pop(s);
                 num1=pop(s);
                 sol=add(num1, num2);
                 push(s, sol);
                 }
                 
              if (strcmp(bst->data.stk, "-")==0){
                 num2=pop(s);
                 num1=pop(s);
                 sol= sub(num1, num2);
                 push(s, sol);
                 }
                 
              if (strcmp(bst->data.stk, "*")==0){
                 num2=pop(s);
                 num1=pop(s);
                 sol=mult(num1, num2);
                 push(s, sol);
                 }
                 
              if (strcmp(bst->data.stk, "/")==0){
                 num2=pop(s);
                 num1=pop(s);
                 sol=divd(num1, num2);
                 push(s, sol);
                 }
              }
}
          
            
           
    


void visit2(FILE *in,TreeNodePtr node){
     printf("%s ",node->data.stk);
     }


void testnode (FILE * out, TreeNodePtr node){
     if (node!=NULL){
        testnode(out, node->left);
        testnode(out, node->right);
        //visit2(out,node);
        fprintf (out, "%s ", node->data.stk);
        }



}
void postOrder (Stack s, TreeNodePtr node){     
     void visit(Stack, TreeNodePtr);
     if (node != NULL){
        postOrder(s, node->left); 
        postOrder(s, node->right);
        visit(s, node);
        }
     }
     
/*   Arithmetic Calculation Functions */

double add (double num1, double num2){
       double sum;
       return sum=num1+num2;
       } //Returns the sum of the digits popped from the top of the stack
       
double sub (double num1, double num2){
       double diff;
       return diff=num1-num2;
       } //Returns the difference between the digits popped from the top of the stack
       
double mult (double num1, double num2){
       double prod;
       return prod=num1*num2;
       } //Returns the product of the digits popped from the top of the stack
       
double divd (double num1, double num2){
       double quot;
       return quot=num1/num2;
       } //Returns the quotient of the digits popped from the top of the stack
       
       
int main (){
    FILE * in = fopen ("input.txt", "r");
    FILE * out = fopen ("output.txt", "w");
    
     
    Stack S;
    BinaryTree bst;
    double popp;
    
    S=createStack();//initialise an empty stack
    bst.root=buildBtree(in); //build Binary Tree
    testnode(out, bst.root);
    postOrder(S, bst.root);
    popp=pop(S);
    fprintf (out, "\n%3.2lf", popp);
    printf("\n");
    
    fclose(in);
    fclose(out);
    system ("pause");
    return 0;
    
}