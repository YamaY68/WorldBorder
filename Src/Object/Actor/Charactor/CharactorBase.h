#pragma once
#include "../ActorBase.h"
#include<map>
#include<memory>
#include <typeindex>
#include <unordered_map>
#include"IState.h"

class CharactorBase :
    public ActorBase
{
public:
	CharactorBase(void);
	virtual ~CharactorBase(void);

	virtual void SubLoad(void) override;
	virtual void SubInit(void) override;
	virtual void SubUpdate(void) override;
	virtual void SubDraw(void) override;
	virtual void SubRelease(void) override;

	void ChangeState(IState* newState);

	template<typename T>
	void AddState(std::unique_ptr<T>state);

	template<typename T>
	void ChangeState(void);

	template<typename T>
	T* GetState(void);

	virtual void SetState(void) {};
	virtual void InitCollider(void) override;
protected:
	int playNumber_;
	std::unordered_map<std::type_index, std::unique_ptr<IState>>stateMap_;
	IState* currentState_ = nullptr;
};

template<typename T>
inline void CharactorBase::AddState(std::unique_ptr<T> state)
{
	stateMap_[typeid(T)] = std::move(state);
}

template<typename T>
inline void CharactorBase::ChangeState(void)
{
	auto it = stateMap_.find(typeid(T));
	if (it != stateMap_.end())
	{
		if (currentState_)currentState_->Exit(this);
		currentState_ = it->second.get();
		currentState_->Enter(this);
	}
}

template<typename T>
inline T* CharactorBase::GetState(void)
{
	auto it = stateMap_.find(typeid(T));
	if (it != stateMap_.end()) {
		return dynamic_cast<T*>(it->second.get());
	}
	return nullptr;
}
