// To create tries, we have to first define how each node of the trie will be like

// So, we will create a class or struct of type Node, which will have:

Node{
  count: Integer showing the number of times a node has been visited
  Next[]: Array of pointer or reference to next node
  isEnding: Boolean showing if a node repersents ending of some string
}

// Pseudocode for Insert operation in a trie:

Insert(curr: node, s: string, index: integer):
  curr.count+= 1
  if(index == s.length):
    curr.isEnding= true
    return

  nextIndex= mapping.get(s[index])

  if(curr.next[nextIndex] == NULL):
    curr.next[nextIndex]= new Node

  insert(curr.next[nextIndex, s, index+1)



  //
