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

#include <iostream>
#include <ignition/common/PluginMacros.hh>

#include "CustomContext.hh"

using namespace ignition;
using namespace gui;

/////////////////////////////////////////////////
CustomContext::CustomContext()
  : Plugin()
{
  auto layout = new QVBoxLayout();
  layout->addWidget(new QLabel(tr("Right-click me!")));
  this->setLayout(layout);
}

/////////////////////////////////////////////////
CustomContext::~CustomContext()
{
}

/////////////////////////////////////////////////
void CustomContext::ShowContextMenu(const QPoint &_pos)
{
  auto menu = new QMenu(tr("Context menu"), this);
  menu->addAction(new QAction("Do something", this));
  menu->addAction(new QAction("Do something else", this));
  menu->addAction(new QAction("Do nothing", this));
  menu->exec(this->mapToGlobal(_pos));
}

// Register this plugin
IGN_COMMON_REGISTER_SINGLE_PLUGIN(ignition::gui::CustomContext,
                                  ignition::gui::Plugin);