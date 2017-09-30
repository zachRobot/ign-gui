/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "ignition/gui/Helpers.hh"
#include "ignition/gui/CollapsibleWidget.hh"

using namespace ignition;
using namespace gui;

/////////////////////////////////////////////////
CollapsibleWidget::CollapsibleWidget(const std::string &_name)
{
  // Button label
  auto buttonLabel = new QLabel(tr(humanReadable(_name).c_str()));
  buttonLabel->setToolTip(tr(_name.c_str()));

  // Button icon
  auto buttonIcon = new QLabel(QString::fromUtf8("\u25b8"));
  buttonIcon->setObjectName("buttonIcon");

  // Button layout
  auto buttonLayout = new QHBoxLayout();
  buttonLayout->addWidget(buttonLabel);
  buttonLayout->addWidget(buttonIcon);
  buttonLayout->setAlignment(buttonIcon, Qt::AlignRight);

  // Button frame
  auto button = new QPushButton();
  button->setLayout(buttonLayout);
  button->setCheckable(true);
  this->connect(button, SIGNAL(toggled(bool)), this, SLOT(Toggle(bool)));

  // Collapsible Layout
  auto mainLayout = new QVBoxLayout;
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setSpacing(0);
  mainLayout->addWidget(button);
  this->setLayout(mainLayout);
}

/////////////////////////////////////////////////
void CollapsibleWidget::Toggle(bool _checked)
{
  // Toggle all items below the button
  for (auto i = 1; i < this->layout()->count(); ++i)
  {
    this->layout()->itemAt(i)->widget()->setVisible(_checked);
  }

  auto icon = this->findChild<QLabel *>("buttonIcon");
  if (_checked)
    icon->setText(QString::fromUtf8("\u25be"));
  else
    icon->setText(QString::fromUtf8("\u25b8"));
}
