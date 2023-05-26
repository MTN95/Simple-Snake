#pragma once

class IObject {
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Clean() = 0;
};