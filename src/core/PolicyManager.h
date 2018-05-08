#ifndef _POLICYMANAGER_H_
#define _POLICYMANAGER_H_

#include "core/Command.h"
#include "core/CommandInterface.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
// The Policy Manager
///////////////////////////////////////////////////////////////////////////////////////////////////

class PolicyManager
{
private:
  PWPolicy                              m_DefaultPolicy;
  PSWDPolicyMap                         m_Policies;  /* The collection of existing policies, on which the policy commands are operating on. */
  CommandInterface&                     m_CommandInterface;  /* The interface to the Core. */
  std::vector<std::unique_ptr<Command>> m_UndoStack; /* The lifo stack with undo commands. */
  std::vector<std::unique_ptr<Command>> m_RedoStack; /* The lifo stack with redo commands. */
  
  /**
   * Adds a policy into the internal collection of policies.
   * Only, command objects are allowed to add policies.
   * See list of friendships.
   */
  void AddPolicy(const StringX& name, const PWPolicy& policy);
  
  /**
   * Removes a policy from the internal collection of policies.
   * Only, command objects are allowed to add policies.
   * See list of friendships.
   */
  void RemovePolicy(const StringX& name);
  
protected:
  
public:
  static const StringX DEFAULT_POLICYNAME;                 /* The name of the default policy. */
  
  PolicyManager(CommandInterface& commandInterface);
  ~PolicyManager();
  
  /**
   * Creates a policy add command of type PolicyCommandAdd, 
   * executes the command and puts it on the Undo Stack.
   */
  void PolicyAdded(const stringT& name, const PWPolicy& policy);
  
  /**
   * Creates a policy remove command of type PolicyCommandRemove, 
   * executes the command and puts it on the Undo Stack.
   */
  void PolicyRemoved(const stringT& name);
  
  /**
   * Creates a policy modify command of type PolicyCommandModify, 
   * executes the command and puts it on the Undo Stack.
   */
  void PolicyModified(const stringT& name, const PWPolicy& original, const PWPolicy& modified);
  
  /**
   * Creates a policy rename command of type PolicyCommandRename, 
   * executes the command and puts it on the Undo Stack.
   */
  void PolicyRenamed(const stringT& oldName, const stringT& newName, const PWPolicy& original, const PWPolicy& modified);
  
  /**
   * Provides the internal collection of policies.
   */
  PSWDPolicyMap GetPolicies() const;
  
  /**
   * Provides a policy with the given name from the internal collection of policies.
   * 
   * If the requested policy doesn't exists the default policy will be provided.
   */
  PWPolicy GetPolicy(const stringT& name) const;
  
  /**
   * Provides the information whether a policy with the given name exists
   * in the internal collection of policies.
   */
  bool HasPolicy(const stringT& name) const;

  /**
   * Provides the default from the internal collection of policies.
   */
  PWPolicy GetDefaultPolicy() const;
  
  /**
   * Removes the default policy from the internal collection of policies.
   */
  void RemoveDefaultPolicy();
  
  /**
   * Provides the number of policies within the internal collection of policies.
   */
  int GetNumberOfPolicies() const;
  
  /**
   * Provides the information whether an undo can be executed, 
   * which is the case if a command exists on the Undo Stack.
   */
  bool CanUndo() const;
  
  /**
   * Provides the information whether an redo can be executed, 
   * which is the case if a command exists on the Redo Stack.
   */
  bool CanRedo() const;
  
  /**
   * Executes undo on the last command from the Undo Stack, if a command exists.
   */
  void Undo();
  
  /**
   * Executes redo on the last command from the Redo Stack, if a command exists.
   */
  void Redo();
};

#endif /* _POLICYMANAGER_H_ */
