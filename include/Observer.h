#pragma once

class Subject;

class Observer {
private:
  Subject *pSub;

public:
  virtual ~Observer();
  virtual void atualizar() = 0;
  void setSub(Subject *pSub);

protected:
  Observer();
};
